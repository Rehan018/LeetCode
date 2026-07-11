class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:

        n = len(nums)

        left = n
        right = -1

        maxSeen = nums[0]
        for i in range(1, n):
            maxSeen = max(maxSeen, nums[i])
            if nums[i] < maxSeen:
                right = i

        minSeen = nums[-1]
        for i in range(n - 2, -1, -1):
            minSeen = min(minSeen, nums[i])
            if nums[i] > minSeen:
                left = i

        return 0 if right == -1 else right - left + 1