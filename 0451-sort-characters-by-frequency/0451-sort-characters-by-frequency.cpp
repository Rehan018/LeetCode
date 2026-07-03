class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> freq;

        for (char c : s)
            ++freq[c];

        vector<string> bucket(s.size() + 1);

        for (auto &[c, cnt] : freq)
            bucket[cnt].append(cnt, c);

        string ans;
        ans.reserve(s.size());

        for (int i = s.size(); i > 0; --i)
            ans += bucket[i];

        return ans;
    }
};