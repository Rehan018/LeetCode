class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {

        vector<int> seen(10, 0);

        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {

                int x = grid[i][j];

                if (x < 1 || x > 9 || seen[x])
                    return false;

                seen[x] = 1;
            }
        }

        for (int i = 0; i < 3; i++) {

            if (grid[r + i][c] +
                    grid[r + i][c + 1] +
                    grid[r + i][c + 2] != 15)
                return false;

            if (grid[r][c + i] +
                    grid[r + 1][c + i] +
                    grid[r + 2][c + i] != 15)
                return false;
        }

        if (grid[r][c] +
                grid[r + 1][c + 1] +
                grid[r + 2][c + 2] != 15)
            return false;

        if (grid[r][c + 2] +
                grid[r + 1][c + 1] +
                grid[r + 2][c] != 15)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        for (int i = 0; i + 2 < m; i++) {
            for (int j = 0; j + 2 < n; j++) {

                if (isMagic(grid, i, j))
                    ans++;
            }
        }

        return ans;
    }
};