impl Solution {
    pub fn pivot_integer(n: i32) -> i32 {

        let total = n * (n + 1) / 2;

        let x = (total as f64).sqrt() as i32;

        if x * x == total {
            x
        } else {
            -1
        }
    }
}