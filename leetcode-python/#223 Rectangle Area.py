

class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        l = max(E, A)
        r = min(C, G)
        u = min(D, H)
        d = max(B, F)
        w = max(0, r-l)
        h = max(0, u-d)
        overlap = w*h
        a = (C-A)*(D-B)
        b = (G-E)*(H-F)
        return a+b-w*h

A = Solution()
print(A.computeArea(-3,0,3,4,0,-1,9,2));