def rob(nums) -> int:
    if len(nums)==0:
        return 0
    elif len(nums)==1:
        return nums[0]
    dp = [0,nums[0]]
    for i in range(2, len(nums)+1):
        dp.append(0)
        dp[i] = max(dp[i-1], dp[i-2]+nums[i-1])
    return dp[-1]

print(rob([1,2,3,1]))

