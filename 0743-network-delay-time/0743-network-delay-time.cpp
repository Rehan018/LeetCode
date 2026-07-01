class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto &e : times)
            graph[e[0]].emplace_back(e[1], e[2]);

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        pq.emplace(0, k);

        while (!pq.empty()) {

            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u])
                continue;

            for (auto &[v, w] : graph[u]) {

                if (dist[v] > d + w) {

                    dist[v] = d + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; ++i) {

            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};