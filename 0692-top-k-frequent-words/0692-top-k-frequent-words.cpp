class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> freq;

        for (auto &w : words)
            ++freq[w];

        auto cmp = [](const pair<string, int> &a, const pair<string, int> &b) {

            if (a.second != b.second)
                return a.second > b.second;

            return a.first < b.first;
        };

        priority_queue<
            pair<string, int>,
            vector<pair<string, int>>,
            decltype(cmp)
        > pq(cmp);

        for (auto &p : freq) {

            pq.push(p);

            if (pq.size() > k)
                pq.pop();
        }

        vector<string> ans(k);

        for (int i = k - 1; i >= 0; --i) {
            ans[i] = pq.top().first;
            pq.pop();
        }

        return ans;
    }
};