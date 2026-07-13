class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], numWanted: int, useLimit: int) -> int:

        items = sorted(zip(values, labels), reverse=True)

        used = {}
        ans = 0
        taken = 0

        for value, label in items:

            if used.get(label, 0) == useLimit:
                continue

            ans += value
            used[label] = used.get(label, 0) + 1
            taken += 1

            if taken == numWanted:
                break

        return ans