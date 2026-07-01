class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<short>> right(m + 1, vector<short>(n + 1, 0));
        vector<vector<short>> down(m + 1, vector<short>(n + 1, 0));

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j]) {
                    right[i][j] = right[i][j + 1] + 1;
                    down[i][j] = down[i + 1][j] + 1;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < m; ++i) {

            for (int j = 0; j < n; ++j) {

                int len = min(right[i][j], down[i][j]);

                while (len > ans) {

                    if (down[i][j + len - 1] >= len &&
                        right[i + len - 1][j] >= len) {

                        ans = len;
                        break;
                    }

                    --len;
                }
            }
        }

        return ans * ans;
    }
};