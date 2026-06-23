class Solution {
public:
    int strongPasswordChecker(string s) {

        int n = s.size();

        bool lower = false;
        bool upper = false;
        bool digit = false;

        for (char c : s) {
            if (islower(c)) lower = true;
            else if (isupper(c)) upper = true;
            else if (isdigit(c)) digit = true;
        }

        int missing = (!lower) + (!upper) + (!digit);

        vector<int> groups;

        for (int i = 0; i < n;) {

            int j = i;

            while (j < n && s[j] == s[i]) {
                j++;
            }

            int len = j - i;

            if (len >= 3) {
                groups.push_back(len);
            }

            i = j;
        }

        if (n < 6) {
            return max(missing, 6 - n);
        }

        int replace = 0;

        for (int len : groups) {
            replace += len / 3;
        }

        if (n <= 20) {
            return max(missing, replace);
        }

        int del = n - 20;
        int remainDel = del;

        vector<int> cnt(3, 0);

        for (int len : groups) {
            cnt[len % 3]++;
        }
        int use = min(cnt[0], remainDel);
        replace -= use;
        remainDel -= use;
        use = min(cnt[1] * 2, remainDel);
        replace -= use / 2;
        remainDel -= use;
        use = min(replace * 3, remainDel);
        replace -= use / 3;
        remainDel -= use;

        return del + max(missing, replace);
    }
};