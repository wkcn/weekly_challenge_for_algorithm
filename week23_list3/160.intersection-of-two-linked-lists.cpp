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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA, *pb = headB;
        while (pa != pb) {
            // 看清变量名，合理用headB和headA!!
            pa = (pa ? pa->next : headB);
            pb = (pb ? pb->next : headA);
        }
        return pa;
    }
};
