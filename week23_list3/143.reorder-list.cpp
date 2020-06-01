/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *pre = nullptr;
        ListNode *p = slow->next;
        slow->next = nullptr;
        while (p) {
            ListNode *next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        slow = head; // append pre
        while (pre) {
            ListNode *next = slow->next;
            slow->next = pre;
            pre = pre->next;
            slow->next->next = next;
            slow = next;
        }
    }
};
