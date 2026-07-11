class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:

        intervals.sort(key=lambda x: x[1])

        removed = 0
        end = intervals[0][1]

        for start, finish in intervals[1:]:

            if start < end:
                removed += 1
            else:
                end = finish

        return removed