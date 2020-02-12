pub struct Solution {}

impl Solution {
    pub fn largest_number(nums: Vec<i32>) -> String {
        if nums.is_empty() {
            return String::new();
        }
        // 处理全为0的特例
        let mut is_allzero = true;
        for k in &nums {
            if *k != 0 {
                is_allzero = false;
                break;
            }
        }
        if is_allzero {
            return "0".to_string();
        }
        let mut nums_str: Vec<String> = Vec::with_capacity(nums.len()); 
        for i in 0..nums.len() {
            nums_str.push(nums[i].to_string());
        }
        nums_str.sort_unstable_by(|x, y| (&(y.to_owned()+x)).cmp(&(x.to_owned()+y)));
        let mut out = String::new();
        for s in &nums_str {
            out += &s;
        }
        out
    }
}

fn main() {
    assert_eq!(Solution::largest_number(vec![10, 2]), "210");
    assert_eq!(Solution::largest_number(vec![3, 30, 34, 5, 9]), "9534330");
    assert_eq!(Solution::largest_number(vec![0]), "0");
}
