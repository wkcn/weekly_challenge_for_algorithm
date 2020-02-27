pub struct Solution {}

impl Solution {
    pub fn three_sum_closest(nums: Vec<i32>, target: i32) -> i32 {
        let mut nums = nums;
        nums.sort();
        let mut best = nums[0] + nums[1] + nums[2];
        for i in 0..nums.len() - 2 {
            let mut j = i + 1;
            let mut k = nums.len() - 1;
            while j < k {
                let su = nums[i] + nums[j] + nums[k];
                if (su - target).abs() < (best - target).abs() {
                    best = su;
                }
                if su < target {
                    j += 1;
                } else {
                    k -= 1;
                }
            }
        }
        best
    }
    pub fn lower_bound(nums: &Vec<i32>, target: i32) -> i32 {
        let mut lo = 0;
        let mut hi = nums.len() as i32;
        while lo < hi {
            let mid = lo + ((hi - lo) >> 1);
            if nums[mid as usize] < target {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        // x < target | target <= x
        lo
    }
    pub fn upper_bound(nums: &Vec<i32>, target: i32) -> i32 {
        let mut lo = 0;
        let mut hi = nums.len() as i32;
        while lo < hi {
            let mid = lo + ((hi - lo) >> 1);
            if nums[mid as usize] <= target {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        // x <= target | target < x
        lo
    }
}

fn main() {
    let nums = vec![1, 3, 3, 3, 5];
    assert_eq!(Solution::lower_bound(&nums, 0), 0);
    assert_eq!(Solution::lower_bound(&nums, 1), 0);
    assert_eq!(Solution::lower_bound(&nums, 2), 1);
    assert_eq!(Solution::lower_bound(&nums, 3), 1);
    assert_eq!(Solution::lower_bound(&nums, 4), 4);
    assert_eq!(Solution::lower_bound(&nums, 5), 4);
    assert_eq!(Solution::lower_bound(&nums, 10), 5);

    assert_eq!(Solution::upper_bound(&nums, 0), 0);
    assert_eq!(Solution::upper_bound(&nums, 1), 1);
    assert_eq!(Solution::upper_bound(&nums, 2), 1);
    assert_eq!(Solution::upper_bound(&nums, 3), 4);
    assert_eq!(Solution::upper_bound(&nums, 4), 4);
    assert_eq!(Solution::upper_bound(&nums, 5), 5);
    assert_eq!(Solution::upper_bound(&nums, 10), 5);

    assert_eq!(Solution::three_sum_closest(vec![-1, 2, 1, -4], 1), 2);
}
