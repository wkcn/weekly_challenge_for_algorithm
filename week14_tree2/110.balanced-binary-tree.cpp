#include "common.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define SOLUTION 2

#if SOLUTION == 1

class Solution {
public:
    bool isBalanced(TreeNode* root) {
      bool balanced = true;
      height(root, balanced);
      return balanced;
    }
    int height(TreeNode* root, bool &balanced) {
      if (!root) return 0;
      int left_height = height(root->left, balanced);
      int right_height = height(root->right, balanced);
      if (abs(left_height - right_height) > 1) balanced = false;
      return max(left_height, right_height) + 1;
    }
};

#elif SOLUTION == 2

struct Node {
  int height, parent, count;
  TreeNode *root;
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
      if (!root) return true;
      vector<Node> nodes;
      queue<int> free;
      queue<int> q;
      PushNode(root, -1, nodes, free, q);
      while (!q.empty()) {
        int id = q.front(); q.pop();
        TreeNode *r = nodes[id].root;
        cout << "VIS: " << r->val << endl;
        if (!r->left && !r->right) {
          // leaf, update height
          int pid = nodes[id].parent;
          int height = 2;
          while (pid != -1) {
            // update parent height and count
            if (--nodes[pid].count == 0) {
              if (abs(nodes[pid].height - height) > 1) return false;
              // free pid
              free.push(pid);
              // next node height
              height = max(nodes[pid].height, height) + 1;
              pid = nodes[pid].parent;
            } else {
              if (height > nodes[pid].height)
                nodes[pid].height = height;
              // 更新一侧的树高度
              break;
            }
          }
          free.push(id);
        } else {
          if (r->left) PushNode(r->left, id, nodes, free, q); 
          if (r->right) PushNode(r->right, id, nodes, free, q); 
        }
      }
      return true;
    }
private:
    int GetNewID(vector<Node> &nodes, queue<int> &free) {
      if (free.empty()) {
        int id = nodes.size();
        nodes.push_back({});
        return id;
      }
      int id = free.front(); free.pop();
      return id;
    }
    void PushNode(TreeNode *root, int parent_id, vector<Node> &nodes, queue<int> &free, queue<int> &q) {
      int id = GetNewID(nodes, free);
      nodes[id].height = 1;
      nodes[id].parent = parent_id;
      nodes[id].root = root;
      nodes[id].count = 0;
      q.push(id);
      if (parent_id != -1) {
        ++nodes[parent_id].count;
      }
    }
};

#endif

int main() {
  TreeNode *root = INPUT_BTREE_LEVEL<TreeNode>();
  cout << Solution().isBalanced(root) << endl;
  return 0;
}
