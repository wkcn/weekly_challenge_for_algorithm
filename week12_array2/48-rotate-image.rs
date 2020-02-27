pub struct Solution {}

impl Solution {
    // reference:
    // https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image
    pub fn rotate_2(matrix: &mut Vec<Vec<i32>>) {
        // 先上下翻转，再Transpose
        let n = matrix.len();
        for r in 0..n/2 {
            matrix.swap(r, n-1-r);
        }
        Self::transpose(matrix);
    }
    pub fn rotate_3(matrix: &mut Vec<Vec<i32>>) {
        // 先Transpose, 再左右翻转
        Self::transpose(matrix);
        let n = matrix.len();
        for r in 0..n {
            for c in 0..n/2 {
                matrix[r].swap(c, n - 1 - c);
            }
        }
    }
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        let n = matrix.len();
        for r in 0..n/2 {
            for c in r..(n-r-1) {
                // 四个需要交换的点
                // (r, c), (c, n-1-r), (n-1-r, n-1-c), (n-1-c, r)
                let tmp = matrix[r][c];
                matrix[r][c] = matrix[n-1-c][r];
                matrix[n-1-c][r] = matrix[n-1-r][n-1-c];
                matrix[n-1-r][n-1-c] = matrix[c][n-1-r];
                matrix[c][n-1-r] = tmp;
            }
        }
    }
    pub fn transpose(matrix: &mut Vec<Vec<i32>>) {
        let n = matrix.len();
        for r in 0..n {
            for c in r+1..n {
                let tmp = matrix[r][c];
                matrix[r][c] = matrix[c][r];
                matrix[c][r] = tmp;
            }
        }
    }
}

fn main() {
    let mut mat = vec![vec![1,2,3],vec![4,5,6],vec![7,8,9]]; 
    Solution::rotate(&mut mat);
    for v in mat {
        println!("{:?}", v);
    }

    let mut mat = vec![vec![1,2,3,4],vec![5,6,7,8],vec![9,10,11,12],vec![13,14,15,16]]; 
    Solution::rotate(&mut mat);
    for v in mat {
        println!("{:?}", v);
    }

}
