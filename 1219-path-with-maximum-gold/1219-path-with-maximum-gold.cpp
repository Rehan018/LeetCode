class Solution {
public:
    int m, n;

    int dfs(vector<vector<int>>& grid, int r, int c) {

        if (r < 0 || r >= m || c < 0 || c >= n ||
            grid[r][c] == 0)
            return 0;

        int gold = grid[r][c];
        grid[r][c] = 0;

        int best = max({
            dfs(grid, r + 1, c),
            dfs(grid, r - 1, c),
            dfs(grid, r, c + 1),
            dfs(grid, r, c - 1)
        });

        grid[r][c] = gold;

        return gold + best;
    }

    int getMaximumGold(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] > 0) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }

        return ans;
    }
};