#include "common.h"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Record {
  int val;
  int left, right;
};

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (!root) return {};
    vector<Record> rec;
    serialize_impl(root, rec);
    int len = rec.size() * sizeof(Record);
    string s;
    s.resize(len);
    memcpy(&s[0], rec.data(), len);
    return s;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data.empty()) return nullptr;
    int len = data.size();
    int n = len / sizeof(Record);
    const Record *rec = reinterpret_cast<const Record*>(data.c_str());
    vector<TreeNode*> ts;
    for (int i = 0; i < n; ++i) {
      ts.push_back(new TreeNode(rec[i].val));
    }
    for (int i = 0; i < n; ++i) {
      TreeNode *r = ts[i];
      if (rec[i].left != -1)
        r->left = ts[rec[i].left];
      if (rec[i].right != -1)
        r->right = ts[rec[i].right];
    }
    return ts[0];
  }
private:
  int serialize_impl(TreeNode *root, vector<Record> &rec) {
    if (!root) return -1;
    int id = rec.size();
    rec.push_back({});
    int left = serialize_impl(root->left, rec);
    int right = serialize_impl(root->right, rec);
    rec[id] = {root->val, left, right};
    return id;
  }
};

int main() {
  TreeNode *root = INPUT_BTREE_LEVEL<TreeNode>();
  Codec codec;
  TreeNode *out = codec.deserialize(codec.serialize(root));
  PRINT_BTREE_LEVEL(out);
  return 0;
}
