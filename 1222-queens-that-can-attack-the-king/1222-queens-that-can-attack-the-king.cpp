class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {

        vector<vector<int>> ans;

        unordered_set<int> st;

        for (auto &q : queens)
            st.insert(q[0] * 8 + q[1]);

        vector<pair<int, int>> dirs = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},
            {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
        };

        for (auto &[dr, dc] : dirs) {

            int r = king[0] + dr;
            int c = king[1] + dc;

            while (r >= 0 && r < 8 &&
                   c >= 0 && c < 8) {

                if (st.count(r * 8 + c)) {
                    ans.push_back({r, c});
                    break;
                }

                r += dr;
                c += dc;
            }
        }

        return ans;
    }
};