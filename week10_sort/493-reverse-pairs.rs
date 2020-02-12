/*
 * 注意一些相等的特殊情况
 * i32的范围
 * 需要考虑所有情况
 */
pub struct Solution {}

impl Solution {
    pub fn reverse_pairs(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        let len = nums.len();
        Self::merge_sort(&mut nums, 0, len) as i32
    }
    fn merge_sort(mut nums: &mut Vec<i32>, start: usize, end: usize) -> usize {
        if end - start <= 1 {
            return 0;
        }
        let mid = (end - start) / 2 + start;
        let mut cnt = Self::merge_sort(&mut nums, start, mid) + Self::merge_sort(&mut nums, mid, end); 
        // merge
        let alen = mid - start;
        let mut buf = Vec::with_capacity(alen);
        for i in 0..alen {
            buf.push(nums[start + i]);
        }
        let mut i = start;
        // let (mut ai, mut bi): (usize, usize) = (0, mid); 
        let mut ai = 0;
        let mut ki = 0;
        // ai可能大于ki
        for bi in mid..end {
            if nums[bi] <= std::i32::MAX / 2 {
                while ki < alen && (nums[bi] >= std::i32::MIN / 2 && buf[ki] <= nums[bi] * 2) {
                    ki += 1;
                }
                if ki < alen {
                    cnt += alen - ki;
                }
            }
            while ai < alen && buf[ai] < nums[bi] {
                nums[i] = buf[ai];
                i += 1;
                ai += 1;
            }
            // buf[ai] >= nums[bi]
            nums[i] = nums[bi];
            i += 1;
        }
        /*
        while (ai < alen || ki < alen) && bi < end {
            if nums[bi] <= std::i32::MAX / 2 {
                // 因为buf[ai] >= nums[bi]时
                // 有可能buf[ai] <= nums[bi] * 2, 但是buf[ai + u] > nums[bi] * 2
                // nums[bi]可能是负数非常小
                // Update ki
                // 可以把下面的语句移动到外面
                while ki < alen && (nums[bi] >= std::i32::MIN / 2 && buf[ki] <= nums[bi] * 2) {
                    ki += 1;
                }
                if ki < alen {
                    cnt += alen - ki;
                }
            }
            // 这里buf[ai]和nums[bi]的比较不能有==
            // 因为它们可能相等且为负数, 此时也存在buf[ai] > nums[bi] * 2
            // -5 < -3, but -5 > -3 * 2
            while ai < alen && buf[ai] < nums[bi] {
                nums[i] = buf[ai];
                i += 1;
                ai += 1;
            }
            // 注意，这里不用循环，因为bi更新后，会出现新的逆序对
            // buf[ai] >= nums[bi]
            nums[i] = nums[bi];
            i += 1;
            bi += 1;
        }
        */
        if ai < alen {
            for e in ai..alen {
                nums[i] = buf[e];
                i += 1;
            }
        }
        cnt
    }
}

fn main() {
    assert_eq!(Solution::reverse_pairs(vec![2147483647,2147483647,-2147483647,-2147483647,-2147483647,2147483647]), 9);
    assert_eq!(Solution::reverse_pairs(vec![-5, -5]), 1);
    assert_eq!(Solution::reverse_pairs(vec![1, 3, 2, 3, 1]), 2);
    assert_eq!(Solution::reverse_pairs(vec![2, 4, 3, 5, 1]), 3);
    assert_eq!(Solution::reverse_pairs(vec![3, 1]), 1);
    assert_eq!(Solution::reverse_pairs(vec![1, 3]), 0);
}
