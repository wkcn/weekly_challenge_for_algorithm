// [GOOD]
pub struct Solution {}

impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        if nums.len() <= 1 {
            return;
        }
        let (mut i, mut j) = (0, nums.len() - 1);
        let mut r = 0;
        // 这里必须包括r == j的情况，[2, 0, 1], 因为r==j时nums[r]的位置可能还没放到
        while r <= j {
            match nums[r] {
                0 => {
                    // 此时nums[r]为0, r 之前不可能存在2 
                    // nums[i] 可能是0 或 1
                    nums.swap(r, i);
                    // i <= r
                    // (i, r, j)
                    i += 1;
                    r += 1;
                }
                2 => {
                    nums.swap(r, j);
                    // 交换后nums[r]可能还是2, 因此r不变
                    // j 是无符号整数
                    if j == 0 {
                        break;
                    }
                    j -= 1;
                }
                _ => r += 1
            }
        }
    }
}

fn main() {
    let mut nums = vec![2,0,2,1,1,0];
    Solution::sort_colors(&mut nums);
    assert_eq!(nums, vec![0,0,1,1,2,2]);

    let mut nums = vec![2,0,1];
    Solution::sort_colors(&mut nums);
    assert_eq!(nums, vec![0,1,2]);

    let mut nums = vec![2];
    Solution::sort_colors(&mut nums);
    assert_eq!(nums, vec![2]);

    let mut nums = vec![2, 1];
    Solution::sort_colors(&mut nums);
    assert_eq!(nums, vec![1, 2]);

    let mut nums = vec![2, 2];
    Solution::sort_colors(&mut nums);
    assert_eq!(nums, vec![2, 2]);
}
