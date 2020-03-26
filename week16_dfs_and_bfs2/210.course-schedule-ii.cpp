class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > conn(numCourses);
        vector<int> indegree(numCourses, 0);
        for (vector<int> &vs : prerequisites) {
          // vs[1] -> vs[0]
          conn[vs[1]].push_back(vs[0]);
          ++indegree[vs[0]];
        }
        queue<int> q;
        vector<int> res;
        for (int i = 0; i < numCourses; ++i) {
          if (indegree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
          int t = q.front(); q.pop();
          res.push_back(t);
          for (int &u : conn[t]) {
            if (--indegree[u] == 0) q.push(u);
          } 
        }
        return numCourses == res.size() ? res : vector<int>{}; // 这里不能直接写{}
    }
};

