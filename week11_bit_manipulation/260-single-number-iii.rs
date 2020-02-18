pub struct Solution {}

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> Vec<i32> {
        let mut v = 0;
        for &k in nums.iter() {
            v ^= k
        }
        /*
        let mut b = 1;
        while v & b == 0 {
            b <<= 1;
        }
        */
        // 一种更方便获取其中1个1的方法
        // 0001010
        // 1110110
        let b = v & (-v); // 获取最后一个1
        let (mut v0, mut v1) = (0, 0);
        for &k in nums.iter() {
            if k & b == 0 {
                v0 ^= k;
            } else {
                v1 ^= k;
            }
        }
        vec![v0, v1]
    }
}

fn main() {
    assert_eq!(Solution::single_number(vec![1, 2, 1, 3, 2, 5]).sort(), vec![3, 5].sort());
}
