class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {

        int n = patience.size();

        vector<vector<int>> graph(n);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> dist(n, -1);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            for (int v : graph[u]) {

                if (dist[v] != -1)
                    continue;

                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }

        int ans = 0;

        for (int i = 1; i < n; ++i) {

            int roundTrip = dist[i] * 2;

            int lastReply;

            if (patience[i] >= roundTrip) {
                lastReply = roundTrip;
            } else {
                int lastSend = ((roundTrip - 1) / patience[i]) * patience[i];
                lastReply = lastSend + roundTrip;
            }

            ans = max(ans, lastReply);
        }

        return ans + 1;
    }
};