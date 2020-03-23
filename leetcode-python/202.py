class Solution:
    def isHappy(self, n: int) -> bool:
        appeared = [n]
        if n==1:
            return True
        while True:
            n = sum([int(i)**2 for i in str(n)])
            if n in appeared:
                return False
            appeared.append(n)
            if n==1:
                return True

a = Solution()
print(a.isHappy(19))