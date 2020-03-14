/*
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
*/
#if SOLUTION == 1
class Solution {
public:
    Node* connect(Node* root) {
        // 层次遍历
        if (!root) return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            Node *pre = nullptr;
            while (len--) {
                Node *r = q.front(); q.pop();
                if (pre) pre->next = r;
                if (r->left) q.push(r->left);
                if (r->right) q.push(r->right);
                pre = r;
            }
        }
        return root;
    }
};
#elif SOLUTION == 2
/*
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
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        Node *cur = root;
        Node *pre = nullptr;
        Node *start = nullptr;
        while (cur) {
            if (cur->left) {
                if (pre) {
                    pre->next = cur->left;
                } else {
                    start = cur->left;
                }
                pre = cur->left;
            }
            if (cur->right) {
                if (pre) {
                    pre->next = cur->right;
                } else {
                    start = cur->right;
                }
                pre = cur->right;
            }
            cur = cur->next;
            if (!cur) {
                cur = start; // 因为lead->left和lead->right不一定是下一层的第一个节点
                pre = nullptr;
                start = nullptr;
            }
        }

        return root;
    }
};
#endif
