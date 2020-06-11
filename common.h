#include <unistd.h>

#include <algorithm>
#include <cassert>
#include <chrono>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

vector<string> split(const string &s, const string &sep) {
  // reference:
  // https://stackoverflow.com/questions/26328793/how-to-split-string-with-delimiter-using-c
  vector<string> out;
  string::size_type lastPos = s.find_first_not_of(sep);
  string::size_type pos = s.find_first_of(sep, lastPos);
  while (pos != string::npos || lastPos != string::npos) {
    out.emplace_back(s.substr(lastPos, pos - lastPos));
    lastPos = s.find_first_not_of(sep, pos);
    pos = s.find_first_of(sep, lastPos);
  }
  return out;
}

template <typename T>
T STRING2NUMBER(const string &s);

template <>
int STRING2NUMBER(const string &s) {
  return stoi(s);
}

template <>
float STRING2NUMBER(const string &s) {
  return stof(s);
}

template <>
double STRING2NUMBER(const string &s) {
  return stod(s);
}

template <>
string STRING2NUMBER(const string &s) {
  return s;
}

template <typename T>
void INPUT_ARRAY(vector<T> &vs) {
  string s;
  getline(cin, s);
  // remove space
  s.erase(0, s.find_first_not_of(" "));
  if (s[0] == '[') {
    vector<string> sp = split(s.substr(1, s.size() - 2), ",");
    for (auto &s : sp) {
      vs.emplace_back(STRING2NUMBER<T>(s));
    }
  } else {
    int n;
    T data;
    stringstream ss;
    if (s.empty()) {
      cin >> n;
    } else {
      ss << s;
      ss >> n;
    }
    while (n--) {
      ss >> data;
      if (ss.eof()) {
        cin >> data;
      }
      vs.push_back(data);
    }
  }
}

template <typename T>
void INPUT_ARRAY2D(vector<vector<T>> &vs) {
  string s;
  do {
    getline(cin, s);
    // remove space
    s.erase(0, s.find_first_not_of(" "));
  } while (s.empty());
  if (s[0] == '[') {
    string buf = s;
    int left = 0;
    while (1) {
      for (char &c : s) {
        if (c == '[')
          ++left;
        else if (c == ']')
          --left;
      }
      if (left == 0) break;
      getline(cin, s);
      buf += s;
    }
    int start;
    for (int i = 0; i < buf.size(); ++i) {
      char &c = buf[i];
      if (c == '[') {
        if (++left == 2) {
          start = i + 1;
        }
      } else if (c == ']') {
        if (left-- == 2) {
          vector<T> rows;
          vector<string> sp = split(buf.substr(start, i - start), ",");
          for (string &sv : sp) {
            rows.push_back(STRING2NUMBER<T>(sv));
          }
          vs.emplace_back(std::move(rows));
        }
      }
    }
  } else {
    int row, col;
    stringstream ss;
    ss << s;
    if (ss.eof())
      cin >> row >> col;
    else
      ss >> row >> col;
    vs.resize(row, vector<T>(col));
    for (int r = 0; r < row; ++r) {
      for (int c = 0; c < col; ++c) {
        if (ss.eof())
          cin >> vs[r][c];
        else
          ss >> vs[r][c];
      }
    }
  }
}

template <typename T>
void PRINT_ARRAY(const vector<T> &vs) {
  bool first = true;
  for (const T &data : vs) {
    if (!first)
      cout << ", ";
    else
      first = false;
    cout << data;
  }
  cout << endl;
}

template <typename T, size_t size>
void PRINT_ARRAY(const array<T, size> &vs) {
  bool first = true;
  for (const T &data : vs) {
    if (!first)
      cout << ", ";
    else
      first = false;
    cout << data;
  }
  cout << endl;
}

vector<int> RANGE(int start, int end) {
  assert(end >= start);
  vector<int> res(end - start);
  for (int i = 0, v = start; v < end; ++i, ++v) {
    res[i] = v;
  }
  return res;
}

vector<int> RANGE(int len) { return RANGE(0, len); }

template <typename TreeNode>
TreeNode *INPUT_BTREE_VLR() {
  stack<TreeNode **> st;
  TreeNode *root = nullptr;
  st.push(&root);
  int n;
  cin >> n;
  while (n--) {
    int v;
    cin >> v;
    TreeNode **p = st.top();
    st.pop();
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
TreeNode *INPUT_BTREE_LEVEL() {
  queue<TreeNode **> q;
  TreeNode *root = nullptr;
  q.push(&root);
  int n;
  cin >> n;
  while (n--) {
    int v;
    cin >> v;
    TreeNode **p = q.front();
    q.pop();
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
void PRINT_BTREE_VLR(TreeNode *root) {
  if (!root) {
    cout << "empty tree" << endl;
  }
  stack<TreeNode *> q;
  q.push(root);
  bool first = true;
  while (!q.empty()) {
    TreeNode *r = q.top();
    q.pop();
    if (!first) cout << " ";
    first = false;
    cout << r->val;
    if (r->right) q.push(r->right);
    if (r->left) q.push(r->left);
  }
  cout << endl;
}

template <typename TreeNode>
void PRINT_BTREE_LEVEL(TreeNode *root) {
  if (!root) {
    cout << "empty tree" << endl;
  }
  queue<TreeNode *> q;
  q.push(root);
  bool first = true;
  while (!q.empty()) {
    TreeNode *r = q.front();
    q.pop();
    if (!first) cout << " ";
    first = false;
    cout << r->val;
    if (r->left) q.push(r->left);
    if (r->right) q.push(r->right);
  }
  cout << endl;
}

template <typename ListNode>
ListNode *INPUT_LIST() {
  int n;
  cin >> n;
  ListNode dummy(0);
  ListNode *tail = &dummy;
  while (n--) {
    int val;
    cin >> val;
    tail->next = new ListNode(val);
    tail = tail->next;
  }
  return dummy.next;
}

template <typename ListNode>
void PRINT_LIST(ListNode *head) {
  bool first = true;
  while (head) {
    if (!first)
      cout << " -> ";
    else
      first = false;
    cout << head->val;
    head = head->next;
  }
  cout << endl;
}

template <typename ListNode, typename T>
ListNode *Vector2List(const vector<T> &vec) {
  ListNode *head = nullptr;
  ListNode **fill = &head;
  for (const T &val : vec) {
    ListNode *p = new ListNode(val);
    *fill = p;
    fill = &((*fill)->next);
  }
  return head;
}

template <typename T>
void PRINT_MATRIX(const vector<vector<T>> &mat) {
  const int row = mat.size();
  if (row == 0) return;
  const int col = mat[0].size();
  if (col == 0) return;
  for (int r = 0; r < row; ++r) {
    bool first = true;
    for (int c = 0; c < col; ++c) {
      if (!first)
        cout << " ";
      else
        first = false;
      cout << mat[r][c];
    }
    cout << endl;
  }
}
#define PRINT_ARRAY2D PRINT_MATRIX

const char HEXCH[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
template <typename T>
string HEX2STR(const T &c) {
  string res;
  int len = sizeof(T);
  const uint8_t *p = reinterpret_cast<const uint8_t *>(&c);
  for (int i = len - 1; i >= 0; --i) {
    uint8_t num = *(p + i);
    res += HEXCH[(num >> 4) & 0xF];
    res += HEXCH[num & 0xF];
  }
  return res;
}

class Timer {
  using time_point = std::chrono::steady_clock::time_point;
  using ms_type = std::chrono::duration<int, ratio<1, 1000>>;
  using milliseconds = std::chrono::milliseconds;

 public:
  Timer(const string name = "") : name_(name) { reset(); }
  void tic() { tic_time_ = get_time_now(); }
  void toc(bool verbose = true) {
    toc_time_ = get_time_now();
    if (verbose) {
      show();
    }
  }
  void show() {
    cout << "Timer";
    if (name_.size()) cout << "[" << name_ << "]";
    cout << ": "
         << "toc: " << get_tic_escape() << "ms tot: " << get_reset_escape()
         << "ms" << endl;
  }
  void reset() {
    reset_time_ = get_time_now();
    tic();
  }
  int get_tic_escape() { return get_time_diff(toc_time_, tic_time_); }
  int get_reset_escape() { return get_time_diff(toc_time_, reset_time_); }

 private:
  time_point get_time_now() { return std::chrono::steady_clock::now(); }
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
