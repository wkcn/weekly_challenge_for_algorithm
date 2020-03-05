#include "common.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
  bool isPalindrome(ListNode* head) {
    // 翻转链表+slow fast
    if (!head) return true;
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *slow = head, *fast = head;
    ListNode *last = &dummy;
    /*
     * dummy(l) -> 1(s, f) -> null
     * dummy -> 1 -> 2(s) -> null(f)
     * dummy -> 1(l) -> 2(s) -> 3(f) -> null
     * dummy -> 1 -> 2(l) -> 3(s) -> 4 -> null(f)
     */
    // 注意，循环的条件影响fast的最终位置
    while (fast && fast->next) {
      fast = fast->next->next;
      ListNode *next = slow->next;
      slow->next = last;
      last = slow;
      slow = next;
    }
    // two cases to recover
    ListNode *left = last;
    ListNode *right = fast ? slow->next : slow;
    last = slow;
    bool palindrome = true;
    while (right) {
      // cout << left->val << ", " << right->val << endl;
      if (left->val != right->val) palindrome = false;
      right = right->next;
      // recover
      ListNode *next = left->next;
      left->next = last;
      last = left;
      left = next;
    }
    return palindrome;
  }
};
#elif SOLUTION == 2
// 递归解法
// https://leetcode.com/problems/palindrome-linked-list/discuss/64490/My-easy-understand-C%2B%2B-solution
class Solution {
public:
  bool isPalindrome(ListNode* head) {
    ListNode *checkNode = head;
    return check(checkNode, head);
  }
  // 递归过程中, checkNode一直指向next
  // check递归结束后，checkNode能指向最后一个节点
  // check会检查p节点和其对应节点字符是否相同
  /*
   * 1 -> 2 -> 3 -> null
   * 1 -> 2 -> null
   */
  bool check(ListNode *&checkNode, ListNode *p) {
    if (!p) return true;
    bool v = check(checkNode, p->next) && (checkNode->val == p->val);
    checkNode = checkNode->next; // 供上一层递归使用
    return v;
  }
};
#endif

int main() {
  ListNode *head = INPUT_LIST<ListNode>();
  cout << Solution().isPalindrome(head) << endl;
  PRINT_LIST(head);
  return 0;
}
