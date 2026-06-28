class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {

        int n = nums.size();
        int pos = 0;

        while (nums[pos] != k)
            pos++;

        unordered_map<int, int> cnt;
        cnt[0] = 1;

        int balance = 0;

        for (int i = pos + 1; i < n; i++) {

            if (nums[i] > k)
                balance++;
            else
                balance--;

            cnt[balance]++;
        }

        int ans = cnt[0] + cnt[1];

        balance = 0;
        for (int i = pos - 1; i >= 0; i--) {

            if (nums[i] > k)
                balance++;
            else
                balance--;

            ans += cnt[-balance];
            ans += cnt[1 - balance];
        }

        return ans;
    }
};