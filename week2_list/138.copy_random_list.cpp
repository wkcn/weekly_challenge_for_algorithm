#include "common.h"

// Definition for a Node.
class Node {
public:
  int val;
  Node* next;
  Node* random;

  Node() {}

  Node(int _val, Node* _next, Node* _random) {
    val = _val;
    next = _next;
    random = _random;
  }
};

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
  Node* copyRandomList(Node* head) {
    map<Node*, Node*> ma;
    Node *p = head;
    while (p) {
      Node *r = new Node();
      ma[p] = r;
      r->val = p->val;
      p = p->next;
    }
    p = head;
    while (p) {
      Node *r = ma[p];
      r->next = ma[p->next];
      r->random = ma[p->random];
      p = p->next;
    }
    return ma[head];
  }
};
#elif SOLUTION == 2

class Solution {
public:
  Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    // copy
    Node *p = head;
    while (p) {
      p->next = new Node(p->val, p->next, nullptr); 
      p = p->next->next;
    }
    // random link
    for (p = head; p; p = p->next->next) {
      if (p->random)
        p->next->random = p->random->next;
    }
    // detach
    p = head;
    Node *ans = head->next;
    while (p) {
      Node *next = p->next->next;
      p->next->next = next ? next->next : nullptr; 
      p->next = next;
      p = next;
    }
    return ans; 
  }
};

#endif

void PrintNode(Node *p) {
  while (p) {
    cout << p->random->val << ", ";
    p = p->next;
  }
  cout << endl;
}

int main() {
  vector<int> data;
  INPUT_ARRAY(data);
  vector<Node> nodes(data.size());
  int len = data.size();
  for (int i = 0; i < len - 1; ++i) nodes[i].next = &nodes[i+1];
  nodes[len-1].next = nullptr;
  for (int i = 0; i < len; ++i) {
    int v = data[i];
    Node &r = nodes[i];
    r.val = i;
    if (v >= 0) {
      r.random = &nodes[v];
    }
  }
  Node *res = Solution().copyRandomList(&nodes[0]);
  PrintNode(&nodes[0]);
  PrintNode(res);
  return 0;
}
