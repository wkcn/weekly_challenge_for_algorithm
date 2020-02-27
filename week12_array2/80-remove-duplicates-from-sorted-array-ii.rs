pub struct Solution {}

impl Solution {
    pub fn remove_duplicates_2(nums: &mut Vec<i32>) -> i32 {
        // 处理空数组！
        if nums.is_empty() {
            return 0;
        }
        let mut cnt = 1;
        let mut k: usize = 1;
        for i in 1..nums.len() {
            if nums[i-1] != nums[i] {
                nums[k] = nums[i];
                k += 1;
                cnt = 1;
            } else {
                cnt += 1;
                if cnt <= 2 {
                    nums[k] = nums[i];
                    k += 1;
                }
            }
        }
        k as i32
    }
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        // reference:
        // https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/discuss/27976/3-6-easy-lines-C%2B%2B-Java-Python-Ruby
        // https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/discuss/27987/Short-and-Simple-Java-solution-(easy-to-understand)
        let mut k = 0;
        let max_cnt = 2;
        for i in 0..nums.len() {
            if k < max_cnt || nums[i] > nums[(k - max_cnt) as usize] {
                nums[k as usize] = nums[i];
                k += 1;
            }
        }
        k
    }
}

fn main() {
    let mut nums = vec![0, 0, 1, 1, 1, 1, 2, 3, 3];
    assert_eq!(Solution::remove_duplicates(&mut nums), 7);
    assert_eq!(nums[..7], [0, 0, 1, 1, 2, 3, 3]);
}
