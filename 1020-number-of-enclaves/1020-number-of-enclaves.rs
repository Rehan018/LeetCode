impl Solution {
    pub fn num_enclaves(mut grid: Vec<Vec<i32>>) -> i32 {

        let m = grid.len();
        let n = grid[0].len();

        fn dfs(grid: &mut Vec<Vec<i32>>, r: i32, c: i32) {

            let m = grid.len() as i32;
            let n = grid[0].len() as i32;

            if r < 0 || r >= m || c < 0 || c >= n {
                return;
            }

            let (x, y) = (r as usize, c as usize);

            if grid[x][y] == 0 {
                return;
            }

            grid[x][y] = 0;

            dfs(grid, r + 1, c);
            dfs(grid, r - 1, c);
            dfs(grid, r, c + 1);
            dfs(grid, r, c - 1);
        }

        for i in 0..m {

            if grid[i][0] == 1 {
                dfs(&mut grid, i as i32, 0);
            }

            if grid[i][n - 1] == 1 {
                dfs(&mut grid, i as i32, (n - 1) as i32);
            }
        }

        for j in 0..n {

            if grid[0][j] == 1 {
                dfs(&mut grid, 0, j as i32);
            }

            if grid[m - 1][j] == 1 {
                dfs(&mut grid, (m - 1) as i32, j as i32);
            }
        }

        let mut ans = 0;

        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 1 {
                    ans += 1;
                }
            }
        }

        ans
    }
}