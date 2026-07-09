class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<set<int>> rows(m), cols(n);

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                rows[i].insert(j);

        for (int j = 0; j < n; ++j)
            for (int i = 0; i < m; ++i)
                cols[j].insert(i);

        queue<array<int,3>> q;
        q.push({0, 0, 1});

        rows[0].erase(0);
        cols[0].erase(0);

        while (!q.empty()) {

            auto [x, y, d] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1)
                return d;

            int reachCol = min(n - 1, y + grid[x][y]);

            auto it = rows[x].upper_bound(y);

            while (it != rows[x].end() && *it <= reachCol) {

                int ny = *it;

                cols[ny].erase(x);

                q.push({x, ny, d + 1});

                it = rows[x].erase(it);
            }

            int reachRow = min(m - 1, x + grid[x][y]);

            auto jt = cols[y].upper_bound(x);

            while (jt != cols[y].end() && *jt <= reachRow) {

                int nx = *jt;

                rows[nx].erase(y);

                q.push({nx, y, d + 1});

                jt = cols[y].erase(jt);
            }
        }

        return -1;
    }
};