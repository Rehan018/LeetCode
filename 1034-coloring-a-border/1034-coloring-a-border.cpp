class Solution {
public:
    int m, n;
    int original;

    vector<pair<int, int>> border;
    vector<vector<bool>> vis;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(vector<vector<int>>& grid, int r, int c) {

        vis[r][c] = true;

        bool isBorder = false;

        for (int k = 0; k < 4; k++) {

            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                isBorder = true;
            }
            else if (grid[nr][nc] != original) {
                isBorder = true;
            }
            else if (!vis[nr][nc]) {
                dfs(grid, nr, nc);
            }
        }

        if (isBorder)
            border.push_back({r, c});
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {

        m = grid.size();
        n = grid[0].size();

        original = grid[row][col];

        vis.assign(m, vector<bool>(n, false));

        dfs(grid, row, col);

        for (auto &[r, c] : border)
            grid[r][c] = color;

        return grid;
    }
};