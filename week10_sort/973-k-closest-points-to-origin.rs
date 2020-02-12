pub struct Solution {}

impl Solution {
    pub fn k_closest(points: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        if points.len() <= k as usize {
            return points;
        }
        // compute distance
        let mut dis = Vec::with_capacity(points.len());
        for p in points.iter() {
            dis.push(p[0] * p[0] + p[1] * p[1]);
        }
        let mut idx: Vec<usize> = (0..points.len() as usize).collect();
        Self::my_nth_element(&mut dis, &mut idx, k as usize);

        let mut out: Vec<Vec<i32> > = Vec::with_capacity(points.len());
        for i in 0..k as usize {
            let j: usize = idx[i];
            out.push(points[j].clone());
        }
        out
    }
    fn my_nth_element(dis: &mut Vec<i32>, idx: &mut Vec<usize>, k: usize) {
        let (mut left, mut right) = (0, idx.len() - 1);
        loop {
            let (mut i, mut j) = (left, right);
            let pivot = dis[left]; // 每次要重新设置pivot
            let pid = idx[left];
            while i < j {
                while i < j && dis[j] >= pivot {
                    j -= 1;
                }
                dis[i] = dis[j];
                idx[i] = idx[j];
                while i < j && dis[i] <= pivot {
                    i += 1;
                }
                dis[j] = dis[i];
                idx[j] = idx[i];
            }
            dis[i] = pivot;
            idx[i] = pid; // 注意这里是左边界，不是left，而是idx[left], 而不是一直是0!!
            // i == j
            if i == k || i == k - 1 {
                // i == k or k - 1都行的, 若只判断i==k, 会出现left > right的情况
                break;
            } else if i < k {
                left = i + 1;
            } else {
                right = i - 1;
            }
        }
    }
}

fn main() {
    let points = vec![vec![1, 3], vec![-2, 2]];
    let k = 1;
    assert_eq!(Solution::k_closest(points, k), vec![vec![-2, 2]]);

    let points = vec![vec![3, 3], vec![5, -1], vec![-2, 4]];
    let k = 2;
    assert_eq!(Solution::k_closest(points, k), vec![vec![3, 3], vec![-2, 4]]);

    let points = vec![vec![0, 0], vec![0, 0]];
    let k = 2;
    assert_eq!(Solution::k_closest(points, k), vec![vec![0, 0], vec![0, 0]]);

    let points = vec![vec![2,2],vec![2,2],vec![2,2],vec![2,2],vec![2,2],vec![2,2],vec![1,1]];
    let k = 1;
    assert_eq!(Solution::k_closest(points, k), vec![vec![1, 1]]);
}
