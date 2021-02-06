class Solution:
    def upper_bound(self, arr, targ):
        left, right = 0, len(arr) - 1
        if arr[right][0] < targ:
            return -1

        while left < right:
            mid = (left + right) // 2
            if arr[mid][0] <= targ:
                left = mid + 1
            else:
                right = mid

        return right if arr[right - 1][0] < targ else right - 1

    def find_ans(self, now, intervals, sz, dp):
        if now >= sz or now == -1:
            return 0
        if dp[now] != -1:
            return dp[now]

        dp[now] = max(self.find_ans(self.upper_bound(intervals, intervals[now][1]), intervals, sz, dp) + 1
                      , self.find_ans(now+1, intervals, sz, dp))
        return dp[now]

    def eraseOverlapIntervals(self, intervals) -> int:
        sz = len(intervals)
        intervals.sort()
        dp = [-1 for _ in range(0, sz)]
        return sz - self.find_ans(0, intervals, sz, dp)
