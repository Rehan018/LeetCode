class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        const uint64_t BASE = 1315423911ULL;

        auto check = [&](int len) -> int {
            unordered_map<uint64_t, vector<int>> mp;
            uint64_t hash = 0, power = 1;

            for (int i = 0; i < len; ++i) {
                hash = hash * BASE + (s[i] - 'a' + 1);
                power *= BASE;
            }
            mp[hash].push_back(0);

            for (int i = len; i < n; ++i) {
                hash = hash * BASE + (s[i] - 'a' + 1);
                hash -= power * (s[i - len] - 'a' + 1);

                auto it = mp.find(hash);
                if (it != mp.end()) {
                    for (int st : it->second) {
                        if (memcmp(s.data() + st, s.data() + i - len + 1, len) == 0)
                            return st;
                    }
                }
                mp[hash].push_back(i - len + 1);
            }
            return -1;
        };

        int lo = 1, hi = n - 1;
        int start = -1, best = 0;

        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int pos = check(mid);
            if (pos != -1) {
                start = pos;
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return start == -1 ? "" : s.substr(start, best);
    }
};