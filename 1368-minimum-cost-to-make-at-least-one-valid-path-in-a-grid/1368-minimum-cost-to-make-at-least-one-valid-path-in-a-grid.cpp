class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int INF = 1e9;
        vector<vector<int>> dist(m, vector<int>(n, INF));
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        dist[0][0] = 0;

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                int cost = (grid[x][y] == dir + 1) ? 0 : 1;

                if (dist[x][y] + cost < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + cost;

                    if (cost == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};