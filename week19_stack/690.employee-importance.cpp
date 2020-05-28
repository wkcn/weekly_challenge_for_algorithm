/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> ma;
        for (Employee* p : employees) {
            ma[p->id] = p;
        }
        set<int> vis;
        queue<int> q;
        vis.insert(id);
        q.push(id);
        int ans = 0;
        while (!q.empty()) {
            int d = q.front(); q.pop();
            ans += ma[d]->importance;
            for (int &u : ma[d]->subordinates) {
                if (!vis.count(u)) {
                    vis.insert(u);
                    q.push(u);
                }
            }
        }
        return ans;
    }
};
