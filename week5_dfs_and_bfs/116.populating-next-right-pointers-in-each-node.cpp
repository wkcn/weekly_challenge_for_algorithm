#include "common.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
  Node* connect(Node* root) {
    if (!root) return nullptr;
    if (!root->left) return root; // perfect binary tree, leaf
    root->left->next = root->right;
    root->right->next = root->next ? root->next->left : nullptr;
    connect(root->left);
    connect(root->right);
    return root;
  }
};
#elif SOLUTION == 2
// O(1) memory 
class Solution {
public:
  Node* connect(Node* root) {
    if (!root) return nullptr;
    Node *r = root, *t = root;
    while (r) {
      while (t) {
        if (t->left) {
          t->left->next = t->right;
          t->right->next = t->next ? t->next->left : nullptr;
          t = t->next;
        } else {
          return root; // leaf
        }
      }
      r = t = r->left;
    }
    return root;
  }
};
#endif

// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/discuss/37461/Java-solution-with-O(1)-memory%2B-O(n)-time
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/discuss/37578/My-simple-non-iterative-C%2B%2B-code-with-O(1)-memory
// 利用next的特性进行遍历, next, left

void PRINT_BTREE_NEXT(Node* root) {
  if (!root) {
    cout << "empty tree" << endl;
  }
  queue<Node*> q;
  q.push(root);
  bool first = true;
  while (!q.empty()) {
    Node* r = q.front(); q.pop();
    if (!first) cout << " ";
    first = false;
    cout << r->val << " -> ";
    if (r->next) cout << r->next->val << endl;
    else cout << "NULL" << endl;
    if (r->left) q.push(r->left);
    if (r->right) q.push(r->right);
  }
  cout << endl;
}


int main() {
  Node *root = INPUT_BTREE_LEVEL<Node>();
  Node *ans = Solution().connect(root);
  PRINT_BTREE_NEXT(ans);
  return 0;
}
