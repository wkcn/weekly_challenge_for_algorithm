struct TNode {
    array<TNode*, 26> nodes;
    bool leaf;
    string s;
    TNode() : nodes{nullptr}, leaf(false){

    }
    ~TNode() {
        for (TNode *r : nodes) delete r;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TNode root;
        for (string &s : words) {
            TNode *p = &root;
            for (char &c : s) {
                TNode *& t = p->nodes[c - 'a'];
                if (t == nullptr) {
                    t = new TNode();
                }
                p = t;
            }
            p->leaf = true;
            p->s = s;
        }
        const int rows = board.size();
        const int cols = board[0].size();
        vector<vector<bool> > vis(rows, vector<bool>(cols, false));
        vector<string> ans;

        function<bool(unsigned int, unsigned int, TNode*)> F;
        F = [&](unsigned int r, unsigned int c, TNode *p) -> bool {
            if (r >= rows || c >= cols) return false;
            if (vis[r][c]) return false;
            char &e = board[r][c];
            p = p->nodes[e - 'a'];
            if (!p) return false;
            if (p->leaf) {
                ans.push_back(p->s);
                p->leaf = false;
            }
            vis[r][c] = true;
            bool valid = F(r + 1, c, p) || \
                F(r - 1, c, p) || \
                F(r, c + 1, p) || \
                F(r, c - 1, p);
            vis[r][c] = false;
            return valid;
        };

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                F(r, c, &root);
            }
        }
        return ans;
    }
};
