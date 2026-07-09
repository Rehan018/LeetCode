class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {

        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });

        int n = points.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {

            int bestY = INT_MIN;

            for (int j = i + 1; j < n; ++j) {

                if (points[j][1] > points[i][1])
                    continue;

                if (points[j][1] > bestY) {
                    ++ans;
                    bestY = points[j][1];
                }
            }
        }

        return ans;
    }
};