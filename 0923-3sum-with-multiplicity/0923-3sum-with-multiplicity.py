class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:

        MOD = 10**9 + 7

        cnt = [0] * 101

        for x in arr:
            cnt[x] += 1

        ans = 0

        for i in range(101):
            if cnt[i] == 0:
                continue

            for j in range(i, 101):
                if cnt[j] == 0:
                    continue

                k = target - i - j

                if k < j or k > 100 or cnt[k] == 0:
                    continue

                if i == j == k:
                    ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) // 6

                elif i == j:
                    ans += cnt[i] * (cnt[i] - 1) // 2 * cnt[k]

                elif j == k:
                    ans += cnt[j] * (cnt[j] - 1) // 2 * cnt[i]

                else:
                    ans += cnt[i] * cnt[j] * cnt[k]

        return ans % MOD