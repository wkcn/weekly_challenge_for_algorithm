class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        unsigned int ans = 0;
        for (int i = 31; i >= 0; --i) {
            ans <<= 1;
            unsigned int tmp = ans | 1;
            unordered_set<unsigned int> se;
            for (int u : nums) {
                u >>= i;
                if (se.find(u ^ tmp) != se.end()) {
                    ans = tmp;
                    break;
                } else {
                    se.insert(u);
                }
            }
        }
        return ans;
    }
};

// 字典树
struct TNode {
    TNode *nodes[2] = {nullptr, nullptr};
};

class Trie {
public:
    Trie() : root(new TNode()) {

    }
    int insert(unsigned int val) {
        TNode *r = root;
        TNode *xorr = root;
        unsigned int u = 0;
        for (int i = 31; i >= 0; --i) {
            unsigned int m = (val >> i) & 1;
            unsigned int re = 1 - m;
            auto &p = r->nodes[m];
            if (!p) p = new TNode();
            r = p;
            auto &xorp = xorr->nodes[re];
            u <<= 1;
            if (!xorp) {
                xorr = xorr->nodes[m];
            }
            else {
                xorr = xorp;
                u |= 1;
            }
        }
        return u;
    }
    ~Trie() {
        if (!root) return;
        queue<TNode*> q;
        q.push(root);
        while (!q.empty()) {
            TNode *r = q.front(); q.pop();
            if (r->nodes[0]) q.push(r->nodes[0]);
            if (r->nodes[1]) q.push(r->nodes[1]);
            delete r;
        }
    }
private:
    TNode *root;
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie tree;
        int ans = 0;
        for (int &v : nums) {
            ans = max(ans, tree.insert(v));
        }
        return ans;
    }
};
