from collections import Counter
from math import factorial

class Solution:
    def countGoodIntegers(self, n: int, k: int) -> int:
        fact = [1] * (n + 1)
        for i in range(1, n + 1):
            fact[i] = fact[i - 1] * i

        good = set()

        half = (n + 1) // 2
        start = 10 ** (half - 1)
        end = 10 ** half

        for x in range(start, end):
            s = str(x)

            if n % 2:
                pal = int(s + s[-2::-1])
            else:
                pal = int(s + s[::-1])

            if pal % k == 0:
                good.add("".join(sorted(str(pal))))

        ans = 0

        for sig in good:
            cnt = Counter(sig)

            total = 0

            for d in "123456789":
                if cnt[d] == 0:
                    continue

                cnt[d] -= 1

                ways = fact[n - 1]
                for v in cnt.values():
                    ways //= fact[v]

                total += ways
                cnt[d] += 1

            ans += total

        return ans