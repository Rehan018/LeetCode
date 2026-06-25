class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {

        unordered_map<int, int> freq;

        for (int card : deck) {
            freq[card]++;
        }

        int g = 0;

        for (auto &[card, cnt] : freq) {
            g = gcd(g, cnt);
        }

        return g >= 2;
    }
};