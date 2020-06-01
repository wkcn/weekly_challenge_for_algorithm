// 还可以找特征，比如在vis -> unvis的时候计数加1
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
    int numComponents(ListNode* head, vector<int>& G) {
        array<bool, 10000> vis{0};
        for (int &v : G) vis[v] = true;
        int ans = 0;
        while (head) {
            if (vis[head->val]) {
                ++ans;
                while (head && vis[head->val]) head = head->next;
            } else {
                head = head->next;
            }
        }
        return ans;
    }
};
