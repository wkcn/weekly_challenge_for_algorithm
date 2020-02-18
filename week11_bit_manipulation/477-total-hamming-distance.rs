pub struct Solution {}

impl Solution {
    pub fn total_hamming_distance(nums: Vec<i32>) -> i32 {
        if nums.len() <= 1 {
            return 0;
        }
        let len = nums.len() as i32;
        // 其实可以把ones消除掉，立即将结果加进tot
        // 对数值移位要比算bit mask好，因为1<<32会溢出
        let mut ones = Vec::with_capacity(32);
        for i in 0..32 {
            let b = 1 << i;
            let mut cnt = 0;
            for &k in nums.iter() {
                if b & k != 0 {
                    cnt += 1;
                }
            }
            ones.push(cnt);
        }
        let mut tot = 0;
        for i in 0..32 {
            tot += ones[i] * (len - ones[i]); 
        }
        tot
    }
}

fn main() {
    assert_eq!(Solution::total_hamming_distance(vec![4, 14, 2]), 6);
}
