class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        int ans = 1;
        if (freq.count(1)) {
            int cnt = freq[1];
            ans = max(ans, (cnt % 2 == 0) ? cnt - 1 : cnt);
        }

        for (auto &[start, _] : freq) {

            if (start == 1) continue;

            long long cur = start;
            int len = 0;

            while (true) {

                if (!freq.count(cur) || freq[cur] == 0) {
                    ans = max(ans, max(1, len - 1));
                    break;
                }

                if (freq[cur] == 1) {
                    ans = max(ans, len + 1);
                    break;
                }
                len += 2;
                if (cur > 1000000000LL) {
                    ans = max(ans, len - 1);
                    break;
                }

                cur = cur * cur;
            }
        }

        return ans;
    }
};