class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack = []
        i = len(nums2)
        high = [-1] * len(nums2)
        while i > 0:
            i -= 1
            while stack and nums2[i] >= stack[0]:
                stack.pop(0)
            top = stack[0] if stack else -1
            high[i] = top
            stack.insert(0, nums2[i])
        pos = {}
        for i, x in enumerate(nums2):
            pos[x] = i
        return [high[pos[i]] for i in nums1]
