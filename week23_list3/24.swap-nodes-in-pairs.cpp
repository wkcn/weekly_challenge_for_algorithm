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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(-1); dummy.next = head;
        ListNode *p = &dummy;
        while (p->next && p->next->next) {
            ListNode *cur1 = p->next;
            ListNode *cur2 = cur1->next;
            ListNode *cur3 = cur2->next;
            p->next = cur2; cur2->next = cur1; cur1->next = cur3;
            p = cur1;
        }
        return dummy.next;
    }
};
