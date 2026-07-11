class Solution:
    def findMinMoves(self, machines: List[int]) -> int:

        total = sum(machines)
        n = len(machines)

        if total % n:
            return -1

        target = total // n
        balance = 0
        ans = 0

        for dresses in machines:
            diff = dresses - target
            balance += diff
            ans = max(ans, abs(balance), diff)

        return ans