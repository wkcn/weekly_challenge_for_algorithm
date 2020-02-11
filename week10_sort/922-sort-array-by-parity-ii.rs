pub struct Solution {}

impl Solution {
    pub fn sort_array_by_parity_ii(a: Vec<i32>) -> Vec<i32> {
        let mut a = a.clone();
        let len = a.len();
        let (mut i, mut j) = (0, 1);
        loop {
            while i < len && a[i] % 2 == 0 {
                i += 2;
            }
            while j < len && a[j] % 2 == 1 {
                j += 2;
            }
            if i < len && j < len {
                a.swap(i, j);
            } else {
                break;
            }
        }
        a
    }
}

fn main() {
    let a = vec![4, 2, 5, 7];
    let out = Solution::sort_array_by_parity_ii(a);
    for v in out {
        println!("{}", v);
    }
}
