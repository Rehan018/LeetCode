class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(n + 1);

        for (auto &e : dislikes) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<int> color(n + 1, -1);

        for (int i = 1; i <= n; ++i) {
            if (color[i] != -1) continue;

            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : g[u]) {
                    if (color[v] == -1) {
                        color[v] = color[u] ^ 1;   
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};