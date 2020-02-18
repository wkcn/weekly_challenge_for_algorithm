pub struct Solution {}

impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        // 负数和0都不可能是2的幂
        // 注意第一个bit是符号位！
        // 2的幂中只有1个1
        // n & (n - 1) 可以移除一个1
        n > 0 && (n & (n - 1)) == 0
    }
}

fn main() {
    assert_eq!(Solution::is_power_of_two(1), true);
    assert_eq!(Solution::is_power_of_two(16), true);
    assert_eq!(Solution::is_power_of_two(218), false);
    assert_eq!(Solution::is_power_of_two(-2147483648), false);
}
