from typing import List

class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        res = []
        if len(nums) == 0:
            return res
        if len(nums) == 1:
            return [str(nums[0])]
        l = 0
        r = 1
        pre = nums[l]
        while r < len(nums):
            if nums[r] != pre+1:
                if r == l+1:
                    res.append(str(nums[l]))
                else:
                    res.append(str(nums[l])+'->'+str(nums[r-1]))
                if r == len(nums)-1:
                    res.append(str(nums[r]))
                l = r
            elif r == len(nums)-1:
                    res.append(str(nums[l])+'->'+str(nums[r]))
            pre = nums[r]
            r += 1
        return res


A = Solution()
print(A.summaryRanges([-1]))

