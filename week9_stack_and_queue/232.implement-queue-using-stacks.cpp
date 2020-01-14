#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class MyQueue {
public:
  /** Initialize your data structure here. */
  MyQueue() {

  }

  /** Push element x to the back of queue. */
  void push(int x) {
    in_st.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int out = peek(); out_st.pop();
    return out;
  }

  /** Get the front element. */
  int peek() {
    if (out_st.empty()) {
      while (!in_st.empty()) {
        out_st.push(in_st.top()); in_st.pop();
      }
    }
    return out_st.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() {
    return out_st.empty() && in_st.empty();
  }
private:
  stack<int> in_st, out_st;
};
#elif SOLUTION == 2
// https://leetcode.com/problems/implement-queue-using-stacks/discuss/64196/0-ms-C%2B%2B-solution-using-one-Stack-w-explanation.

class MyQueue {
public:
  /** Initialize your data structure here. */
  MyQueue() {

  }

  /** Push element x to the back of queue. */
  void push(int x) {
    // use system stack
    if (st.empty()) {
      st.push(x);
    } else {
      /*
       * --------------------
       * front          back|
       * --------------------
       */
      int front_elem = st.top(); st.pop();
      push(x);
      st.push(front_elem);
    }
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int target = peek();
    st.pop();
    return target;
  }

  /** Get the front element. */
  int peek() {
    return st.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() {
    return st.empty();
  }
private:
  stack<int> st;
};
#endif

int main() {
  MyQueue queue;
  queue.push(1);
  queue.push(2);
  cout << queue.peek() << endl;  // returns 1
  cout << queue.pop() << endl;   // returns 1
  cout << queue.empty() << endl; // returns false
  return 0;
}
