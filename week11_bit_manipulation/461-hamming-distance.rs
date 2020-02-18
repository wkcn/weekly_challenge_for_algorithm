pub struct Solution {}

impl Solution {
    pub fn hamming_distance(x: i32, y: i32) -> i32 {
        let mut z = x ^ y;
        let mut cnt = 0;
        while z != 0 {
            z &= z - 1;
            cnt += 1;
        }
        cnt
    }
}

fn main() {
    assert_eq!(Solution::hamming_distance(1, 4), 2);
}
