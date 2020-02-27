pub struct Solution {}

impl Solution {
    pub fn remove_duplicates_2(nums: &mut Vec<i32>) -> i32 {
        if nums.is_empty() {
            return 0;
        }
        let mut v = nums[0];
        let mut k = 1;
        for i in 1..nums.len() {
            if nums[i] != v {
                nums[k as usize] = nums[i];
                v = nums[i];
                k += 1;
            }
        }
        k
    }
    // 其实不需要变量v, 比较相邻两个数是否相同即可
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        if nums.is_empty() {
            return 0;
        }
        let mut k = 1;
        for i in 1..nums.len() {
            if nums[i-1] != nums[i] {
                nums[k as usize] = nums[i];
                k += 1;
            }
        }
        k
    }
}

fn main() {
    let mut nums = vec![0,0,1,1,1,2,2,3,3,4];
    assert_eq!(Solution::remove_duplicates(&mut nums), 5);
    assert_eq!(nums[..5], [0,1,2,3,4]);
}
