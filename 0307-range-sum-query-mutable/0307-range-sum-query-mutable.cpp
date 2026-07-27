class NumArray {
    vector<int> bit, nums;
    int n;

    void add(int idx, int delta) {
        for (++idx; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }

    int query(int idx) {
        int sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        bit.assign(n + 1, 0);

        for (int i = 0; i < n; ++i)
            add(i, nums[i]);
    }

    void update(int index, int val) {
        add(index, val - nums[index]);
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        return query(right) - (left ? query(left - 1) : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */