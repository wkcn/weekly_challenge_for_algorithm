pub struct Solution {}

impl Solution {
    pub fn first_missing_positive(nums: Vec<i32>) -> i32 {
        // store a[i] value i+1
        let mut nums = nums;
        let n = nums.len();
        for i in 0..n {
            while nums[i] >= 1 && nums[i] <= n as i32 {
                let ind = (nums[i] - 1) as usize;
                if nums[ind] == nums[i] {
                    break;
                }
                nums.swap(ind, i);
            }
        }
        for i in 0..n {
            if nums[i] != i as i32 + 1 {
                return (i + 1) as i32;
            }
        }
        return (n + 1) as i32;
    }
}

fn main() {
    assert_eq!(Solution::first_missing_positive(vec![1, 2, 0]), 3);
    assert_eq!(Solution::first_missing_positive(vec![3, 4, -1, 1]), 2);
    assert_eq!(Solution::first_missing_positive(vec![7, 8, 9, 10, 11, 12]), 1);
}
