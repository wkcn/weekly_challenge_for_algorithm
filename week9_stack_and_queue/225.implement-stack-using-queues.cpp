#include "common.h"

class MyStack {
public:
  /** Initialize your data structure here. */
  MyStack() {
      
  }
  
  /** Push element x onto stack. */
  void push(int x) {
    /*
     * ----------------------
     * front             back
     * ----------------------
     * stack.top
     */
    int siz = q.size();
    q.push(x);
    for (int i = 0; i < siz; ++i) {
      q.push(q.front()); 
      q.pop();
    }
      
  }
  
  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int target = top();
    q.pop();
    return target;
  }
  
  /** Get the top element. */
  int top() {
    return q.front();
  }
  
  /** Returns whether the stack is empty. */
  bool empty() {
    return q.empty();
  }
private:
  queue<int> q;
};

int main() {
  MyStack stack;

  stack.push(1);
  stack.push(2);
  cout << stack.top() << endl;   // returns 2
  cout << stack.pop() << endl;   // returns 2
  cout << stack.empty() << endl; // returns false
  return 0;
}
