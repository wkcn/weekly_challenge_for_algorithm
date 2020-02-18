pub struct Solution {}

impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut major = nums[0];
        let mut count = 1;
        for &v in nums[1..].iter() {
            if count == 0 {
                major = v;
                count = 1;
            } else {
                if major == v {
                    count += 1;
                } else {
                    count -= 1;
                }
            }
        }
        major
    }
}

// 另一种方法：
// 逐个bit计算超过半数的是0还是1
// 即按bit进行投票

fn main() {
    assert_eq!(Solution::majority_element(vec![3, 2, 3]), 3);
    assert_eq!(Solution::majority_element(vec![2, 2, 1, 1, 1, 2, 2]), 2);
}
