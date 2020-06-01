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
// TODO: 试一下题解的方法？
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode dummy1, dummy2;
        ListNode *p1 = &dummy1, *p2 = &dummy2;
        while (head) {
            p1->next = head; p1 = p1->next;
            head = head->next;
            if (!head) break;
            p2->next = head; p2 = p2->next;
            head = head->next;
        }
        p1->next = dummy2.next;
        p2->next = nullptr;
        return dummy1.next;
    }
};
