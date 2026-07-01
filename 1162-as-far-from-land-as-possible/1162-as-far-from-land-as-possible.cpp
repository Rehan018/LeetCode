class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        int n = grid.size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    q.emplace(i, j);
            }
        }

        if (q.empty() || q.size() == n * n)
            return -1;

        static constexpr int dir[5] = {-1, 0, 1, 0, -1};

        int dist = -1;

        while (!q.empty()) {

            int sz = q.size();
            ++dist;

            while (sz--) {

                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < 4; ++k) {

                    int nx = x + dir[k];
                    int ny = y + dir[k + 1];

                    if ((unsigned)nx < (unsigned)n &&
                        (unsigned)ny < (unsigned)n &&
                        grid[nx][ny] == 0) {

                        grid[nx][ny] = 1;
                        q.emplace(nx, ny);
                    }
                }
            }
        }

        return dist;
    }
};