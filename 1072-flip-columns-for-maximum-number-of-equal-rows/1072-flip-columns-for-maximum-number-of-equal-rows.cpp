class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {

        unordered_map<string, int> mp;
        int ans = 0;

        for (auto &row : matrix) {

            string key;

            for (int x : row) {

                if (row[0] == 1)
                    key += char('0' + (1 - x));
                else
                    key += char('0' + x);
            }

            ans = max(ans, ++mp[key]);
        }

        return ans;
    }
};