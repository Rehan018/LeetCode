class Solution {
public:
    struct BIT {
        int n;
        vector<int> bit;

        BIT(int n) : n(n), bit(n + 1, 0) {}

        void update(int idx, int val) {
            for (++idx; idx <= n; idx += idx & -idx)
                bit[idx] += val;
        }

        int query(int idx) {
            int res = 0;
            for (++idx; idx > 0; idx -= idx & -idx)
                res += bit[idx];
            return res;
        }
    };

    int numTeams(vector<int>& rating) {
        vector<int> vals = rating;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();

        BIT left(m), right(m);

        for (int x : rating)
            right.update(lower_bound(vals.begin(), vals.end(), x) - vals.begin(), 1);

        int ans = 0;

        for (int x : rating) {
            int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin();

            right.update(idx, -1);

            int leftLess = left.query(idx - 1);
            int leftGreater = left.query(m - 1) - left.query(idx);

            int rightLess = right.query(idx - 1);
            int rightGreater = right.query(m - 1) - right.query(idx);

            ans += leftLess * rightGreater + leftGreater * rightLess;

            left.update(idx, 1);
        }

        return ans;
    }
};