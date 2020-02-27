pub struct Solution {}

impl Solution {
    pub fn insert_2(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        // 分情况调试，比较复杂
        let mut ans: Vec<Vec<i32> > = Vec::new();
        let mut new_interval = new_interval;
        let mut finished = false;
        for it in intervals.iter() {
            if finished || it[1] < new_interval[0] {
                println!("{:?} and {:?}, push", it, new_interval);
                ans.push(it.clone());
            } else {
                if it[1] <= new_interval[1] {
                    if it[0] < new_interval[0] {
                        new_interval[0] = it[0];
                    }
                    println!("{:?} and {:?}, left", it, new_interval);
                } else {
                    // it[1] > new_interval[1]
                    if it[0] <= new_interval[1] {
                        new_interval[1] = it[1];
                        if it[0] < new_interval[0] {
                            new_interval[0] = it[0];
                        }
                        println!("{:?} and {:?}, left2", it, new_interval);
                    } else {
                        ans.push(new_interval.clone());
                        ans.push(it.clone());
                        finished = true;
                        println!("{:?} and {:?}, finish", it, new_interval);
                    }
                }
            }
        }
        // 处理intervals为空的情况
        if !finished {
            ans.push(new_interval);
        }
        ans
    }
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        // 其实分三种情况就行了！
        let mut ans: Vec<Vec<i32> > = Vec::new();
        let mut new_interval = new_interval;
        let len = intervals.len();
        let mut i = 0;
        // part 1
        while i < len && intervals[i][1] < new_interval[0] {
            ans.push(intervals[i].clone());
            i += 1;
        }
        // part 2
        while i < len && intervals[i][0] <= new_interval[1] {
            if intervals[i][0] < new_interval[0] {
                new_interval[0] = intervals[i][0];
            }
            if intervals[i][1] > new_interval[1] {
                new_interval[1] = intervals[i][1];
            }
            i += 1;
        }
        ans.push(new_interval);
        // part 3
        for j in i..len {
            ans.push(intervals[j].clone());
        }
        ans
    }
}

fn main() {
    let intervals = vec![vec![1, 3], vec![6, 9]];
    let new_interval = vec![2, 5];
    assert_eq!(Solution::insert(intervals, new_interval), vec![vec![1, 5], vec![6, 9]]);

    println!("=================");

    let intervals = vec![vec![1, 2], vec![3, 5], vec![6, 7], vec![8, 10], vec![12,16]];
    let new_interval = vec![4, 8];
    assert_eq!(Solution::insert(intervals, new_interval), vec![vec![1, 2], vec![3, 10], vec![12, 16]]);
}
