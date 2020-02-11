pub struct Solution {}

impl Solution {
    pub fn intersection(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut nums1 = nums1;
        let mut nums2 = nums2;
        nums1.sort();
        nums2.sort();
        let mut result = Vec::new();
        let (mut i, mut j) = (0, 0);
        while i < nums1.len() && j < nums2.len() {
            if nums1[i] == nums2[j] {
                result.push(nums1[i]);
                Self::step_for(&mut i, &nums1);
            } else if nums1[i] < nums2[j] {
                Self::step_for(&mut i, &nums1);
            } else {
                Self::step_for(&mut j, &nums2);
            }
        }
        result
    }

    fn step_for(i: &mut usize, nums: &Vec<i32>) {
        let v = nums[*i];
        *i += 1;
        while *i < nums.len() && nums[*i] == v {
            *i += 1;
        }
    }
}

fn main() {
    let a = vec![1, 2, 2, 1];
    let b = vec![2, 2];
    let out = Solution::intersection(a, b);
    for k in out {
        println!("{}", k);
    }
}
