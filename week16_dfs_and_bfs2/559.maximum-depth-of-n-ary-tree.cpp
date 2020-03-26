/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#if SOLUTION == 1
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        int t = 0;
        for (Node *r : root->children) {
            int u = maxDepth(r);
            if (u > t) t = u;
        }
        return t + 1;
    }
};
#elif SOLUTION == 2
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        queue<pair<Node*, int> > q;
        q.push({root, 1});
        int best = 1;
        while (!q.empty()) {
            auto [p, h] = q.front(); q.pop();
            if (h > best) best = h;
            ++h;
            for (Node *r : p->children) {
                q.push({r, h});
            }
        }
        return best;
    }
};
#endif
