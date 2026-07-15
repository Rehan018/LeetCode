class Solution:
    def nearestPalindromic(self, n: str) -> str:

        length = len(n)
        num = int(n)

        candidates = set()

        candidates.add(10 ** (length - 1) - 1)
        candidates.add(10 ** length + 1)

        prefix = int(n[:(length + 1) // 2])

        for p in (prefix - 1, prefix, prefix + 1):

            s = str(p)

            if length % 2:
                pal = int(s + s[:-1][::-1])
            else:
                pal = int(s + s[::-1])

            candidates.add(pal)

        candidates.discard(num)

        ans = -1

        for x in candidates:

            if ans == -1:
                ans = x
            elif abs(x - num) < abs(ans - num):
                ans = x
            elif abs(x - num) == abs(ans - num) and x < ans:
                ans = x

        return str(ans)