from typing import List

class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        # if len(nums)==0 or k<0 or t<0:
        #     return False
        # l = nums[0]
        # r = nums[0]
        # for i in nums:
        #     if i < l:
        #         l = i
        #     elif i > r:
        #         r = i
        # bucks = [[]]
        # i = l
        # if t == 0:
        #     t = 1
        # while i < r:
        #     i += t
        #     bucks.append([])
        # for i in range(len(nums)):
        #     bucks[int((nums[i]-l)/t)].append(i)
        # print(bucks)
        # for i in range(len(bucks)-1):
        #     temp = bucks[i]+bucks[i+1]
        #     temp.sort()
        #     for j in range(len(temp)-1):
        #         if temp[j+1]-temp[j]<k and nums[temp[j+1]]-nums[temp[j]]<t:
        #             return True
        # return False
        bucket = dict()
        if t < 0: return False
        for i in range(len(nums)):
            nth = nums[i] // (t + 1)
            if nth in bucket:
                return True
            if nth - 1 in bucket and abs(nums[i] - bucket[nth - 1]) <= t:
                return True
            if nth + 1 in bucket and abs(nums[i] - bucket[nth + 1]) <= t:
                return True
            bucket[nth] = nums[i]
            if i >= k: bucket.pop(nums[i - k] // (t + 1))
        return False


nums = [1,5,9,1,5,9]
A = Solution()
print(A.containsNearbyAlmostDuplicate(nums, 2, 3))

print(A.containsNearbyAlmostDuplicate([1,2,3,1], 3, 0))
print(A.containsNearbyAlmostDuplicate([1,0,1,1], 1, 2))