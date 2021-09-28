from typing import List
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        left = [0 for i in heights]
        right = [0 for i in heights]
        left_stack, right_stack = [], []
        for i in range(len(heights)):
            while left_stack and heights[i] <= left_stack[0][0]:
                left_stack.pop(0)
            left_edge = left_stack[0] if left_stack else [0, -1]
            left[i] = i-left_edge[1]-1
            left_stack.insert(0, [heights[i], i])

            j = len(heights) - i - 1
            while right_stack and heights[j] <= right_stack[0][0]:
                right_stack.pop(0)
            right_edge = right_stack[0] if right_stack else [0, len(heights)]
            right[j] = right_edge[1]-j-1
            right_stack.insert(0, [heights[j], j])
        
        print(left, right)
        return max([heights[i] * (left[i] + right[i] + 1) for i in range(len(heights))])


print(Solution().largestRectangleArea([2,1,5,6,2,3]))