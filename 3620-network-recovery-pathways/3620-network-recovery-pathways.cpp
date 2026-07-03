class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> graph(n);
        vector<int> indegree(n, 0);

        int hi = -1;

        for (auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            indegree[e[1]]++;
            hi = max(hi, e[2]);
        }
        vector<int> topo;
        topo.reserve(n);

        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &[v, w] : graph[u])
                if (--indegree[v] == 0)
                    q.push(v);
        }

        auto check = [&](int limit) {

            const long long INF = (1LL << 60);

            vector<long long> dist(n, INF);
            dist[0] = 0;

            for (int u : topo) {

                if (dist[u] == INF)
                    continue;

                if (u != 0 && u != n - 1 && !online[u])
                    continue;

                for (auto &[v, w] : graph[u]) {

                    if (w < limit)
                        continue;

                    if (v != 0 && v != n - 1 && !online[v])
                        continue;

                    if (dist[v] > dist[u] + w)
                        dist[v] = dist[u] + w;
                }
            }

            return dist[n - 1] <= k;
        };

        if (!check(0))
            return -1;

        int lo = 0;
        int ans = 0;

        while (lo <= hi) {

            int mid = lo + ((hi - lo) >> 1);

            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};