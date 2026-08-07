class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        auto next = [&](int i) {
            return ((i + nums[i]) % n + n) % n;
        };

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;

            bool dir = nums[i] > 0;
            int slow = i, fast = i;

            while (true) {
                int s = next(slow);
                if ((nums[s] > 0) != dir) break;

                int f = next(fast);
                if ((nums[f] > 0) != dir) break;

                f = next(f);
                if ((nums[f] > 0) != dir) break;

                slow = s;
                fast = f;

                if (slow == fast) {
                    if (slow == next(slow))
                        break;
                    return true;
                }
            }
            int cur = i;
            while (nums[cur] != 0 && (nums[cur] > 0) == dir) {
                int nxt = next(cur);
                nums[cur] = 0;
                if (nxt == cur) break;
                cur = nxt;
            }
        }

        return false;
    }
};