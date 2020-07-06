/*
 * 用双端队列记录正在处理的数字。
每次从队列中取出最前面的一个数，记为a, 剩下的数依次作为b，进行四则运算，得到的结果v放到双端队列的末尾，调用函数go进行下一轮的计算，计算结束后，将队列末尾元素（也就是v）弹出队列。

需要注意的几点：

由于除法是实数除法，需要用浮点数float存储结果。
作除法时，除数不能为0.
在判断结果是否为24时，由于浮点数误差，需要使用abs(x - y) < eps的判断形式，并且eps不能设得太小。当eps=10e-7时，对于3, 3, 8, 8这个样例，由于误差大于10e-7，是判断不出和24近似的。
当输入为3, 3, 8, 8时，有两种情况为24
1，8 / (3 - 8 / 3) = 24
2，8 / (3 - (8 / 3)) = 24

作者：wkcn
链接：https://leetcode-cn.com/problems/24-game/solution/c-shuang-duan-dui-lie-de-miao-yong-36xing-you-jie-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
#include "common.h"

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        deque<float> q;
        for (int x : nums) q.push_back(x);
        return go(q);
    }
    bool go(deque<float> &q) {
        const int len = q.size();
        if (len == 1) {
            return abs(q.front() - 24) < eps;
        }
        for (int i = 0; i < len; ++i) {
            // 注意a, b的类型是float
            float a = q.front(); q.pop_front();
            for (int j = 1; j < len; ++j) {
                float b = q.front(); q.pop_front();
                if (gen(q, a + b) ||
                    gen(q, a - b) ||
                    gen(q, a * b) ||
                    (b ? gen(q, a / b) : 0)) return true; // 要避免除以0
                q.push_back(b);
            }
            q.push_back(a);
        }
        return false;
    }
    inline bool gen(deque<float> &q, float v) {
        q.push_back(v);
        bool b = go(q);
        q.pop_back();
        return b;
    }
private:
    float eps = 1e-5;
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().judgePoint24(nums) << endl;
  return 0;
}
