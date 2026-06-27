class Solution {
public:
    int m, n;

    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};

    int containVirus(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        while (true) {

            vector<vector<pair<int,int>>> regions;
            vector<unordered_set<int>> frontiers;
            vector<int> walls;

            vector<vector<int>> vis(m, vector<int>(n, 0));

            for (int i = 0; i < m; i++) {

                for (int j = 0; j < n; j++) {

                    if (grid[i][j] == 1 && !vis[i][j]) {

                        regions.push_back({});
                        frontiers.push_back({});
                        walls.push_back(0);

                        dfs(grid, i, j, vis,
                            regions.back(),
                            frontiers.back(),
                            walls.back());
                    }
                }
            }

            if (regions.empty())
                break;

            int idx = -1;
            int mx = 0;

            for (int i = 0; i < frontiers.size(); i++) {

                if ((int)frontiers[i].size() > mx) {

                    mx = frontiers[i].size();
                    idx = i;
                }
            }

            if (mx == 0)
                break;

            ans += walls[idx];
            for (auto &p : regions[idx]) {

                grid[p.first][p.second] = -1;
            }
            for (int i = 0; i < regions.size(); i++) {

                if (i == idx)
                    continue;

                for (int code : frontiers[i]) {

                    int r = code / n;
                    int c = code % n;

                    grid[r][c] = 1;
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& grid,
             int r,
             int c,
             vector<vector<int>>& vis,
             vector<pair<int,int>>& region,
             unordered_set<int>& frontier,
             int& wall) {

        vis[r][c] = 1;

        region.push_back({r, c});

        for (int k = 0; k < 4; k++) {

            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= m ||
                nc < 0 || nc >= n)
                continue;

            if (grid[nr][nc] == 1) {

                if (!vis[nr][nc])
                    dfs(grid, nr, nc, vis,
                        region, frontier, wall);
            }
            else if (grid[nr][nc] == 0) {

                wall++;
                frontier.insert(nr * n + nc);
            }
        }
    }
};