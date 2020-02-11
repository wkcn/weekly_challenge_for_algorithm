pub struct Solution {}

impl Solution {
    pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut nums1 = nums1;
        let mut nums2 = nums2;
        nums1.sort();
        nums2.sort();
        let mut result = Vec::new();
        let (mut i, mut j) = (0, 0);
        while i < nums1.len() && j < nums2.len() {
            if nums1[i] == nums2[j] {
                result.push(nums1[i]);
                i += 1; j += 1;
            } else if nums1[i] < nums2[j] {
                i += 1;
            } else {
                j += 1;
            }
        }
        result
    }
}

fn main() {
    let out = Solution::intersect(vec![1, 2, 2, 1], vec![2, 2]);
    assert_eq!(out, [2, 2]);

    let out = Solution::intersect(vec![4, 9, 5], vec![9, 4, 9, 8, 4]);
    assert_eq!(out, [4, 9]);
}
