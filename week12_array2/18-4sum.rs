pub struct Solution {}

impl Solution {
    pub fn four_sum(nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let len = nums.len();
        if len < 4 {
            return Vec::new();
        }
        let mut nums = nums;
        nums.sort();
        println!("{:?}", nums);

        let mut res: Vec<Vec<i32> > = Vec::new();

        let mut forward: Vec<i32> = vec![len as i32; len];
        let mut backward: Vec<i32> = vec![-1 as i32; len];
        let mut j = 0;
        let mut v = nums[0];
        for i in 1..len {
            if nums[i] != v {
                for k in j..i {
                    forward[k] = i as i32;
                }
                j = i;
                v = nums[i];
            }
        }

        j = len;
        v = nums[len - 1];
        for i in (0..len-1).rev() {
            if nums[i] != v {
                for k in i+1..j {
                    backward[k] = i as i32;
                }
                j = i + 1;
                v = nums[i];
            }
        }

        println!("forward {:?}", forward);
        println!("backward {:?}", backward);

        let mut buf: Vec<i32> = Vec::new(); 
        Self::get_k_sum(&mut res, &mut buf, 4, target, &nums, 0, (&forward, &backward)); 

        res
    }

    fn get_k_sum(mut res: &mut Vec<Vec<i32> >, mut buf: &mut Vec<i32>, k: i32, target: i32, nums: &Vec<i32>, start: i32, fb: (&Vec<i32>, &Vec<i32>)) {
        // 注意：如果用slice, 会出现相对坐标的参考系不一样，因此这里还是用回绝对坐标！
        let len = nums.len();
        let (forward, backward) = fb;
        if k == 2 {
            let mut i: i32 = start;
            let mut j: i32 = (len - 1) as i32;
            while i < j {
                let su = nums[i as usize] + nums[j as usize];
                if su == target {
                    let mut tmp = buf.clone();
                    tmp.push(nums[i as usize]);
                    tmp.push(nums[j as usize]);
                    res.push(tmp);
                    i = forward[i as usize];
                    j = backward[j as usize];
                } else if su < target {
                    i = forward[i as usize];
                } else {
                    j = backward[j as usize];
                }
            }
        } else {
            if nums[len - 1] * k < target {
                // 过小
                return;
            }
            let mut i: i32 = start;
            while i <= (len as i32) - k {
                let v = nums[i as usize];
                if v * k > target {
                    // 过大
                    return;
                }
                buf.push(v);
                Self::get_k_sum(&mut res, &mut buf, k - 1, target - v, &nums, i + 1, (&forward, &backward)); 
                buf.pop();
                i = forward[i as usize];
            }
        }
    }
}

fn check(nums: Vec<i32>, target: i32, mut result: Vec<Vec<i32> >) {
    let mut out = Solution::four_sum(nums, target);
    out.sort();
    for i in 0..out.len() {
        out[i].sort();
    }
    result.sort();
    for i in 0..result.len() {
        result[i].sort();
    }
    assert_eq!(out, result);

}

fn main() {
    check(vec![1, 0, -1, 0, -2, 2], 0, vec![vec![-1, 0, 0, 1], vec![-2, -1, 1, 2], vec![-2, 0, 0, 2]]);
    check(vec![-1, 0, 1, 2, -1, -4], -1, vec![vec![-4, 0, 1, 2], vec![-1, -1, 0, 1]]);
}
