class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const auto &a, const auto &b) {
            if (a[0] != b[0]) return a[0] > b[0];
            return a[1] < b[1];
        });

        vector<vector<int>> ans;
        ans.reserve(people.size());

        for (auto &p : people)
            ans.insert(ans.begin() + p[1], p);

        return ans;
    }
};