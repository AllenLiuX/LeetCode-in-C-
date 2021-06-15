from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        target1, target2 = -1, -1
        count1, count2 = 0, 0
        for i in nums:
            if i == target1:
                count1 += 1
            elif i == target2:
                count2 += 1
            elif count1 == 0:
                target1 = i
                count1 += 1
            elif count2 == 0:
                target2 = i
                count2 += 1
            else:
                count1 -= 1
                count2 -= 1

        size1, size2 = 0, 0
        for i in nums:
            if i == target1:
                size1 += 1
            if i == target2:
                size2 += 1
        res = []
        if size1 > len(nums)/3:
            res.append(target1)
        if size2 > len(nums) / 3 and target1 != target2:
            res.append(target2)
        return res






