class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:

        def countDigits(x):
            cnt = [0] * 10
            while x:
                cnt[x % 10] += 1
                x //= 10
            return cnt

        target = countDigits(n)

        for i in range(31):
            if target == countDigits(1 << i):
                return True

        return False