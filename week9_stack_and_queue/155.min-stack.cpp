#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
typedef long long LL;

class MinStack {
public:
  /** initialize your data structure here. */
  MinStack() : min_value(0) {

  }

  void push(int x) {
    if (st.empty()) {
      // 注意对第一个元素的处理
      min_value = x;
      st.push(0);
    } else {
      st.push(LL(x) - min_value);
      if (x < min_value)
        min_value = x;
    }
    // push: 3, 5, 6, 2, 1, 4
    // minv: 3, 3, 3, 2, 1, 1
    // inst: 3, 2, 3, -1, -1, 3
  }

  void pop() {
    if (st.top() < 0) {
      min_value -= st.top();
    }
    st.pop();
  }

  int top() {
    // 注意分情况考虑
    // 0L是long int, 0LL是0 long long int
    return max(0LL, st.top()) + min_value;
  }

  int getMin() {
    return min_value;
  }
private:
  LL min_value;
  stack<LL> st; // elem is value - min_value
};

#elif SOLUTION == 2

class MinStack {
public:
  /** initialize your data structure here. */
  MinStack() : min_value(INT_MAX) {

  }

  void push(int x) {
    // 这里<=必须包含等于的条件，样例：0, 1, 0
    if (x <= min_value) {
      st.push(min_value);
      min_value = x;
    }
    st.push(x);
  }

  void pop() {
    if (st.top() == min_value) {
      st.pop();
      min_value = st.top();
    }
    st.pop();
  }

  int top() {
    return st.top();
  }

  int getMin() {
    return min_value;
  }
private:
  int min_value;
  stack<int> st; // elem is value - min_value
};

#endif

int main() {
  MinStack minStack;
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  cout << minStack.getMin() << endl;//   --> Returns -3.
  minStack.pop();
  cout << minStack.top() << endl; //     --> Returns 0.
  cout << minStack.getMin() << endl; //  --> Returns -2.
  return 0;
}
