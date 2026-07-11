class Solution:
    def longestPalindrome(self, s: str) -> int:

        freq = {}

        for c in s:
            freq[c] = freq.get(c, 0) + 1

        ans = 0
        odd = False

        for cnt in freq.values():

            ans += cnt // 2 * 2

            if cnt & 1:
                odd = True

        return ans + odd