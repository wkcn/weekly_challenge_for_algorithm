use std::io::{self, Read};

pub struct Solution {}

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        Solution::get_char_array(&s) == Solution::get_char_array(&t)
    }
    fn get_char_array(s: &String) -> Vec<i32> {
        let mut arr = vec![0; 26];
        for c in s.chars() {
            arr[(c as u8 - 'a' as u8) as usize] += 1;
        }
        return arr;
    }
}

fn main() {
    let mut s = String::new();
    let mut t = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    io::stdin().read_to_string(&mut t).unwrap();
    println!("{}", Solution::is_anagram(s, t));
}
