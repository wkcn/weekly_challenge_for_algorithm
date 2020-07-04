class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // 父文件夹 + '/' 是子文件夹的字串
        sort(folder.begin(), folder.end());
        vector<string> res;
        int j = -1;
        for (int i = 0; i < folder.size(); ++i) {
            if (j == -1) {
                j = i;
                res.push_back(folder[i]);
            } else {
                // 判断folder[j]是不是folder[i]的父文件夹
                string &parent = folder[j];
                string &child = folder[i];
                if (!isparent(parent, child)) {
                    j = i;
                    res.push_back(child);
                }
            }
        }
        return res;
    }
    bool isparent(string &parent, string &child) {
        if (parent.size() > child.size()) return false;
        int i = 0;
        for (; i < parent.size(); ++i) {
            if (parent[i] != child[i]) return false;
        }
        if (i == child.size()) return true; // same name
        return child[i] == '/';
    }
};
