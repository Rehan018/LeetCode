class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {

        int ans = events[0][0];
        int mx = events[0][1];
        int prev = events[0][1];

        for (int i = 1; i < events.size(); ++i) {

            int duration = events[i][1] - prev;

            if (duration > mx ||
               (duration == mx && events[i][0] < ans)) {

                mx = duration;
                ans = events[i][0];
            }

            prev = events[i][1];
        }

        return ans;
    }
};