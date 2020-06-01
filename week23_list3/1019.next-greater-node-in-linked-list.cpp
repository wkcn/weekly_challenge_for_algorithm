/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if (!head) return {};
        int len = 0;
        ListNode *p = head;
        while (p) {
            ++len;
            p = p->next;
        }
        vector<int> ans(len, 0);
        stack<pair<int, int> > st; // (ind, num)
        p = head;
        int i = 0;
        while (p) {
            while (!st.empty() && p->val > st.top().second) {
                int ind = st.top().first; st.pop();
                ans[ind] = p->val;
            }
            st.push({i, p->val});
            ++i; p = p->next;
        }
        return ans;
    }
};
