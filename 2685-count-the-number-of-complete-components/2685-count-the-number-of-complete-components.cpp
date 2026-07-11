class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<char> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; ++i) {

            if (vis[i])
                continue;

            queue<int> q;
            q.push(i);
            vis[i] = 1;

            long long nodes = 0;
            long long degreeSum = 0;

            while (!q.empty()) {

                int u = q.front();
                q.pop();

                ++nodes;
                degreeSum += graph[u].size();

                for (int v : graph[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }

            if (degreeSum == nodes * (nodes - 1))
                ++ans;
        }

        return ans;
    }
};