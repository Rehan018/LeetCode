class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        n = len(row)
        pos = [0] * n

        for i, x in enumerate(row):
            pos[x] = i

        ans = 0

        for i in range(0, n, 2):
            x = row[i]
            y = x ^ 1

            if row[i + 1] == y:
                continue

            ans += 1
            j = pos[y]

            pos[row[i + 1]] = j
            row[j] = row[i + 1]

            row[i + 1] = y
            pos[y] = i + 1

        return ans