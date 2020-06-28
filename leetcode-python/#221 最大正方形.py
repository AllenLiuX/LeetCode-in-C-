#
# @lc app=leetcode.cn id=221 lang=python3
#
# [221] 最大正方形
#

# @lc code=start
from typing import List
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        dp = matrix.copy()
        res = 0
        if len(dp) == 0:
            return 0
        for i in range(len(dp[0])):
            if int(dp[0][i]) > 0:
                res = 1
        for i in range(len(dp)):
            if int(dp[i][0]) > 0:
                res = 1
        for i in range(1, len(dp)):
            for j in range(1, len(dp[0])):
                if int(matrix[i][j]) > 0:
                    dp[i][j] = min(int(matrix[i][j - 1]), int(matrix[i - 1][j - 1]), int(matrix[i - 1][j])) + 1
                    if dp[i][j] > res:
                        res = dp[i][j]
        return res ** 2

# @lc code=end

A = Solution()
test = [[1,0,1,0,0],[1,0,1,1,1],[1,1,1,1,1],[1,0,0,1,0]]
print(A.maximalSquare(test))
