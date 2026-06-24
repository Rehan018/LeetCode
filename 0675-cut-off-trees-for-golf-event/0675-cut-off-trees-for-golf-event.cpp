class Solution {
public:

    int bfs(vector<vector<int>>& forest,
            int sr, int sc,
            int tr, int tc) {

        if (sr == tr && sc == tc) return 0;

        int m = forest.size();
        int n = forest[0].size();

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m,
            vector<bool>(n, false));

        q.push({sr, sc});
        vis[sr][sc] = true;

        vector<pair<int,int>> dirs = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        int steps = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [r,c] = q.front();
                q.pop();

                if (r == tr && c == tc)
                    return steps;

                for (auto &[dr,dc] : dirs) {

                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n ||
                        vis[nr][nc] ||
                        forest[nr][nc] == 0)
                        continue;

                    vis[nr][nc] = true;
                    q.push({nr,nc});
                }
            }

            steps++;
        }

        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {

        int m = forest.size();
        int n = forest[0].size();

        vector<tuple<int,int,int>> trees;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (forest[i][j] > 1) {
                    trees.push_back(
                        {forest[i][j], i, j}
                    );
                }
            }
        }

        sort(trees.begin(), trees.end());

        int sr = 0;
        int sc = 0;
        int ans = 0;

        for (auto &[h, tr, tc] : trees) {

            int dist =
                bfs(forest, sr, sc, tr, tc);

            if (dist == -1)
                return -1;

            ans += dist;

            sr = tr;
            sc = tc;
        }

        return ans;
    }
};