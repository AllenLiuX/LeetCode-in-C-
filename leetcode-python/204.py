import math
def countprime(n):
    # if n < 2:
    #     return 0
    # nums = list(range(2, n))
    # i = 2
    # k = 0
    # while i < math.sqrt(n):
    #     for j in range(2, int(n / i) + 1):
    #         if j * i in nums:
    #             nums.remove(j * i)
    #     k += 1
    #     i = nums[k]
    # return len(nums)
    if n < 3:
        return 0
    nums = [1] * n
    nums[0] = 0
    nums[1] = 0
    for i in range(2, int(n ** 0.5) + 1):
        if nums[i] == 1:
            nums[i * i:n:i] = [0] * len(nums[i * i:n:i])
    return sum(nums)

print(countprime(100000))