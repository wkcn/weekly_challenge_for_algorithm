pub struct Solution {}

impl Solution {
    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
        let mut out = vec![vec![-1; n as usize]; n as usize];
        let dir = [(1, 0), (0, 1), (-1, 0), (0, -1)]; // (dx, dy)
        let mut pos = (-1, 0);
        let mut d = 0;
        for k in 1..=n*n {
            loop {
                let new_pos = (pos.0 + dir[d].0, pos.1 + dir[d].1);
                if new_pos.0 >= 0 && new_pos.1 >= 0 && new_pos.0 < n && new_pos.1 < n {
                    if out[new_pos.1 as usize][new_pos.0 as usize] == -1 {
                        out[new_pos.1 as usize][new_pos.0 as usize] = k;
                        pos = new_pos;
                        break;
                    }
                }
                d = (d + 1) % 4;
            }
        }
        out
    }
}

fn main() {
    let mat = Solution::generate_matrix(3);
    for v in mat {
        println!("{:?}", v);
    }
}
