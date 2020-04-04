# 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
#
# 注意:
#
# 每个数组中的元素不会超过 100
# 数组的大小不会超过 200
# 示例 1:
#
# 输入: [1, 5, 11, 5]
#
# 输出: true
#
# 解释: 数组可以分割成 [1, 5, 5] 和 [11].
#  
#
# 示例 2:
#
# 输入: [1, 2, 3, 5]
#
# 输出: false
#
# 解释: 数组不能分割成两个元素和相等的子集.
#
# 来源：力扣（LeetCode）
# 链接：https://leetcode-cn.com/problems/partition-equal-subset-sum
# 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



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
