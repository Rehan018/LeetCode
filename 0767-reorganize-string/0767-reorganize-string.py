class Solution:
    def reorganizeString(self, s: str) -> str:

        n = len(s)

        freq = [0] * 26

        for c in s:
            freq[ord(c) - ord('a')] += 1

        mx = max(freq)

        if mx > (n + 1) // 2:
            return ""

        ans = [''] * n

        idx = freq.index(mx)
        pos = 0

        while freq[idx] > 0:
            ans[pos] = chr(idx + ord('a'))
            pos += 2
            freq[idx] -= 1

        for i in range(26):
            while freq[i] > 0:
                if pos >= n:
                    pos = 1
                ans[pos] = chr(i + ord('a'))
                pos += 2
                freq[i] -= 1

        return "".join(ans)