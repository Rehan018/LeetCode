class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 0;
        int n = chars.size();

        while (i < n) {
            char c = chars[i];
            int cnt = 0;

            while (i < n && chars[i] == c) {
                ++i;
                ++cnt;
            }

            chars[j++] = c;

            if (cnt > 1) {
                string s = to_string(cnt);
                for (char ch : s)
                    chars[j++] = ch;
            }
        }

        return j;
    }
};