#include <iostream>
#include <chrono>
#include <functional>
#include <list>
#include <memory>
#include <vector>
#include <random>
#include <string>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <map>
#include <climits>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <cstring>
#include <unistd.h>
using namespace std;

template <typename T>
void INPUT_ARRAY(vector<T> &vs) {
  int n;
  cin >> n;
  T data;
  while(n--) {
    cin >> data;
    vs.push_back(data);
  }
}

template <typename T>
void INPUT_ARRAY2D(vector<vector<T> > &vs) {
  int row, col;
  cin >> row >> col;
  vs.resize(row, vector<T>(col));
  for (int r = 0; r < row; ++r) {
    for (int c = 0; c < col; ++c) {
      cin >> vs[r][c];
    }
  }
}

template <typename T>
void PRINT_ARRAY(const vector<T> &vs) {
  bool first = true;
  for (const T &data : vs) {
    if (!first) cout << ", ";
    else first = false;
    cout << data;
  }
  cout << endl;
}

template <typename TreeNode>
TreeNode* INPUT_BTREE_VLR() {
  stack<TreeNode**> st;
  TreeNode* root = nullptr;
  st.push(&root);
  int n;
  cin >> n;
  while (n--) {
    int v;
    cin >> v;
    TreeNode** p = st.top(); st.pop();
    if (v) {
      // valid
      *p = new TreeNode(v);
      st.push(&((*p)->right));
      st.push(&((*p)->left));
    }
  }
  return root;
}

template <typename TreeNode>
TreeNode* INPUT_BTREE_LEVEL() {
  queue<TreeNode**> q;
  TreeNode* root = nullptr;
  q.push(&root);
  int n;
  cin >> n;
  while (n--) {
    int v;
    cin >> v;
    TreeNode** p = q.front(); q.pop();
    if (v) {
      // valid
      *p = new TreeNode(v);
      q.push(&((*p)->left));
      q.push(&((*p)->right));
    }
  }
  return root;
}

template <typename TreeNode>
void PRINT_BTREE_VLR(TreeNode* root) {
  if (!root) {
    cout << "empty tree" << endl;
  }
  stack<TreeNode*> q;
  q.push(root);
  bool first = true;
  while (!q.empty()) {
    TreeNode* r = q.top(); q.pop();
    if (!first) cout << " ";
    first = false;
    cout << r->val;
    if (r->right) q.push(r->right);
    if (r->left) q.push(r->left);
  }
  cout << endl;
}

template <typename TreeNode>
void PRINT_BTREE_LEVEL(TreeNode* root) {
  if (!root) {
    cout << "empty tree" << endl;
  }
  queue<TreeNode*> q;
  q.push(root);
  bool first = true;
  while (!q.empty()) {
    TreeNode* r = q.front(); q.pop();
    if (!first) cout << " ";
    first = false;
    cout << r->val;
    if (r->left) q.push(r->left);
    if (r->right) q.push(r->right);
  }
  cout << endl;
}

template <typename ListNode>
ListNode* INPUT_LIST() {
  int n;
  cin >> n;
  ListNode dummy(0);
  ListNode *tail = &dummy;
  while(n--) {
    int val;
    cin >> val;
    tail->next = new ListNode(val);
    tail = tail->next;
  }
  return dummy.next;
}

template <typename ListNode>
void PRINT_LIST(ListNode* head) {
  bool first = true;
  while(head) {
    if (!first) cout << " -> ";
    else first = false;
    cout << head->val;
    head = head->next;
  }
  cout << endl;
}


template <typename T>
void PRINT_MATRIX(const vector<vector<T> > &mat) {
  int row = mat.size();
  int col = mat[0].size();
  for (int r = 0; r < row; ++r) {
    bool first = true;
    for (int c = 0; c < col; ++c) {
      if (!first) cout << " ";
      else first = false;
      cout << mat[r][c];
    }
    cout << endl;
  }
}


class Timer {
using time_point = std::chrono::steady_clock::time_point;
using ms_type = std::chrono::duration<int, ratio<1, 1000> >;
using milliseconds = std::chrono::milliseconds;
public:
  Timer(const string name="") : name_(name) {reset();}
  void tic() {
    tic_time_ = get_time_now();
  }
  void toc(bool verbose = true) {
    toc_time_ = get_time_now();
    if (verbose) {
      show();
    }
  }
  void show() {
    cout << "Timer";
    if (name_.size()) cout << "[" << name_ << "]";
    cout << ": " << "toc: " << get_tic_escape() << "ms tot: " << get_reset_escape() << "ms" << endl;
  }
  void reset() {
    reset_time_ = get_time_now();
    tic();
  }
  int get_tic_escape() {
    return get_time_diff(toc_time_, tic_time_);
  }
  int get_reset_escape() {
    return get_time_diff(toc_time_, reset_time_);
  }
private:
  time_point get_time_now() {
    return std::chrono::steady_clock::now();
  }
  int get_time_diff(time_point a, time_point b) {
    milliseconds diff = std::chrono::duration_cast<milliseconds>(a - b);
    return diff.count(); 
  }
private:
  string name_;
  time_point reset_time_;
  time_point tic_time_;
  time_point toc_time_;
};
