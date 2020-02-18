// [GOOD] 好题
/*
 * Reference:
 * https://leetcode.com/problems/single-number-ii/discuss/43360/The-simplest-solution-ever-with-clear-explanation
 * https://leetcode.com/problems/single-number-ii/discuss/43296/An-General-Way-to-Handle-All-this-sort-of-questions.
 */
pub struct Solution {}

impl Solution {
    // https://leetcode.com/problems/single-number-ii/discuss/43295/Detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers
    // x = x | 0
    // x = x ^ 0
    // 状态转换
    // 因为存储3需要两个bit, 用b1, b0两个变量存储高低位
    // 只统计1的个数，数到3就变为0
    // b1, b0 -> b1, b0
    //  0,  0 ->  0,  1
    //  0,  1 ->  1,  0
    //  1,  0 ->  0,  0
    //  1,  1 ->  X,  X
    //  
    //1\0    0    1
    //0     01   10
    //1     00   xx
    //
    //计算下一个状态, 只用关注什么情况为1
    // 对于低位b0:
    // 对于高位b1: 
    // 加法可以用异或^模拟
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut b0 = 0;
        let mut b1 = 0;
        for &k in nums.iter() {
            // 先更新高位
            b1 ^= b0 & k; // 当k为1且b0为1时，更新b1的值
            b0 ^= k;
            let mask = !(b0 & b1);
            b1 &= mask;
            b0 &= mask;
            // println!("value: {:32b}, b1: {:32b}, b0: {:32b}", k, b1, b0); 
        }
        b0
    }
    // naive method
    pub fn single_number_naive_bit_count(nums: Vec<i32>) -> i32 {
        // 考虑bit位：
        // 0 + 0 + 0 = 0
        // 1 + 1 + 1 = 3
        // 而且0 % 3 = 0, 3 % 3 = 0
        let mut i = 1;
        let mut res = 0;
        for _ in 0..32 {
            let mut cnt = 0;
            for &k in nums.iter() {
                if k & i != 0 {
                    cnt += 1;
                }
            }
            if cnt % 3 != 0{
                res |= i;
            }
            i <<= 1;
        }
        res
    }
}

fn main() {
    assert_eq!(Solution::single_number(vec![2, 2, 3, 2]), 3);
    assert_eq!(Solution::single_number(vec![0, 1, 0, 1, 0, 1, 99]), 99);
}
