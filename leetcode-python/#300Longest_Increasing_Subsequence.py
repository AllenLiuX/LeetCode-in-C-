from typing import List

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        max_length = [1 for _ in nums]
        for i in range(1, len(nums)):
            max_num = 0
            for j in range(i):
                if max_length[j] > max_num and nums[j] < nums[i]:
                    max_num = max_length[j]
            max_length[i] = max_num + 1
        return max(max_length)

    
a = Solution().lengthOfLIS([0,1,0,3,2,3])
print(a)