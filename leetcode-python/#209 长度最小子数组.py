# 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。
#
# 示例: 
#
# 输入: s = 7, nums = [2,3,1,2,4,3]
# 输出: 2
# 解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
# 进阶:
#
# 如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
#
# 来源：力扣（LeetCode）
# 链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum
# 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

from typing import List

class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        res = 0
        l = r = 0
        sum = 0
        for i in range(len(nums)):
            sum += nums[i]
            if sum >= s:
                r = i
                res = i+1
                break
        while r <= len(nums)-1:
            if res == 1:
                return res
            sum -= nums[l]
            l += 1
            while sum<s and r+1<len(nums):
                r += 1
                sum += nums[r]
            if sum>=s and r-l+1<res:
                res = r-l+1
            if r==len(nums)-1 and sum-nums[l]<s:
                break
        return res


        
A = Solution()
print(A.minSubArrayLen(7, [2,3,1,2,4,3]))