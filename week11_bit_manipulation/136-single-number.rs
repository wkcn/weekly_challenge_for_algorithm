pub struct Solution {}

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut v = 0;
        for &k in nums.iter() {
            v ^= k;
        }
        v
    }
}

fn main() {
    assert_eq!(Solution::single_number(vec![2, 2, 1]), 1);
}
