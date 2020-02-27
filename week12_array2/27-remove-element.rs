pub struct Solution {}

impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut k = 0;
        for i in 0..nums.len() {
            if nums[i] != val {
                nums[k as usize] = nums[i];
                k += 1;
            }
        }
        k
    }
}

fn main() {
    let mut nums = vec![3, 2, 2, 3];
    assert_eq!(Solution::remove_element(&mut nums, 3), 2);
    assert_eq!(nums.sort(), vec![2, 2].sort());
}
