/*
 * 
给定一个整数数组 A，你可以从某一起始索引出发，跳跃一定次数。在你跳跃的过程中，第 1、3、5... 次跳跃称为奇数跳跃，而第 2、4、6... 次跳跃称为偶数跳跃。

你可以按以下方式从索引 i 向后跳转到索引 j（其中 i < j）：

在进行奇数跳跃时（如，第 1，3，5... 次跳跃），你将会跳到索引 j，使得 A[i] <= A[j]，A[j] 是可能的最小值。如果存在多个这样的索引 j，你只能跳到满足要求的最小索引 j 上。
在进行偶数跳跃时（如，第 2，4，6... 次跳跃），你将会跳到索引 j，使得 A[i] >= A[j]，A[j] 是可能的最大值。如果存在多个这样的索引 j，你只能跳到满足要求的最小索引 j 上。
（对于某些索引 i，可能无法进行合乎要求的跳跃。）
如果从某一索引开始跳跃一定次数（可能是 0 次或多次），就可以到达数组的末尾（索引 A.length - 1），那么该索引就会被认为是好的起始索引。

返回好的起始索引的数量。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/odd-even-jump
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include "common.h"

// 注意两个位置的数字相等的情况
// std::sort是不稳定排序
// std::stable_sort是稳定排序
// TODO: 用集合set::upper_bound做
class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        //  0,  1,  2,  3,  4
        // 10, 13, 12, 14, 15
        // sort idx: 0, 2, 1, 3, 4
        const int len = A.size();
        if (len <= 1) return len;
        vector<int> inds(len);
        for (int i = 0; i < len; ++i) inds[i] = i;
        stable_sort(inds.begin(), inds.end(), [&](const int &a, const int &b) {
            return A[a] < A[b];
        });
        vector<int> oddnext = get_next(inds);
        for (int i = 0; i < len; ++i) inds[i] = i; // 是否需要？
        stable_sort(inds.begin(), inds.end(), [&](const int &a, const int &b) {
            return A[a] > A[b];
        });
        vector<int> evennext = get_next(inds);
        
        vector<int> oddvis(len, false), evenvis(len, false);
        oddvis.back() = true; evenvis.back() = true;
        for (int i = len - 2; i >= 0; --i) {
            if (oddnext[i] != -1) {
                oddvis[i] = evenvis[oddnext[i]];
            }
            if (evennext[i] != -1) {
                evenvis[i] = oddvis[evennext[i]];
            }
        }
        int ans = accumulate(oddvis.begin(), oddvis.end(), 0);
        return ans;
    }
    vector<int> get_next(vector<int> &inds) {
        stack<int> st;
        vector<int> res(inds.size(), -1);
        for (int &i : inds) {
            while (!st.empty() && i > st.top()) {
                res[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};

int main() {
  vector<int> A;
  INPUT_ARRAY(A);
  cout << Solution().oddEvenJumps(A) << endl;
  return 0;
}
