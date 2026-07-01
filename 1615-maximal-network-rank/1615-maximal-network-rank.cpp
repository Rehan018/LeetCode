class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

        vector<int> degree(n, 0);
        vector<vector<bool>> connected(n, vector<bool>(n, false));

        for (auto &r : roads) {

            ++degree[r[0]];
            ++degree[r[1]];

            connected[r[0]][r[1]] = true;
            connected[r[1]][r[0]] = true;
        }

        int ans = 0;

        for (int i = 0; i < n; ++i) {

            for (int j = i + 1; j < n; ++j) {

                ans = max(ans,
                          degree[i] + degree[j] - connected[i][j]);
            }
        }

        return ans;
    }
};