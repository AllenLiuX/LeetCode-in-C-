# 统计所有小于非负整数 n 的质数的数量。
#
# 示例:
#
# 输入: 10
# 输出: 4
# 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

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