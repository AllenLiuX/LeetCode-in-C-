from typing import List


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        size = len(nums)
        s = sum(nums)
        if s%2:
            return False
        target = s/2
        dp = [[False for _ in range (target+1)] for _ in range(size)]
        for i in range(target+1):
            if nums[0] == i:
                dp[0][i] = True
        for i in range(1, size):
            for j in range(target+1):
                if j<nums[i]:
                    dp[i][j] = dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-nums[i]]
        return dp[-1][-1]
