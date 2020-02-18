pub struct Solution {}

impl Solution {
    pub fn count_bits(num: i32) -> Vec<i32> {
        let mut res = Vec::with_capacity((num + 1) as usize);
        res.push(0);
        for i in 1..=num {
            // 用i & (i - 1)消除一个1
            // res.push(res[(i & (i-1)) as usize]+1);
            
            // 用移位消除末位
            res.push(res[(i >> 1) as usize] + (i & 1));
        }
        res
    }
}

fn main() {
    assert_eq!(Solution::count_bits(2), vec![0,1,1]);
    assert_eq!(Solution::count_bits(5), vec![0,1,1,2,1,2]);
}
