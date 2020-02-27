pub struct Solution {}

impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        // 可以先处理空位，从后向前
        let mut i = m - 1;
        let mut j = n - 1;
        let mut k = nums1.len() as i32 - 1;
        while i >= 0 && j >= 0 {
            if nums1[i as usize] <= nums2[j as usize] {
                nums1[k as usize] = nums2[j as usize];
                k -= 1;
                j -= 1;
            } else {
                nums1[k as usize] = nums1[i as usize];
                k -= 1;
                i -= 1;
            }
        }
        if i < 0 {
            for k in 0..=j {
                nums1[k as usize] = nums2[k as usize];
            }
        }
    }
}

fn main() {
    let mut nums1 = vec![1, 2, 3, 0, 0, 0];
    let mut nums2 = vec![2, 5, 6];
    Solution::merge(&mut nums1, 3, &mut nums2, 3); 
    assert_eq!(nums1, vec![1, 2, 2, 3, 5, 6]);
}
