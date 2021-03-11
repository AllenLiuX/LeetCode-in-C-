

def quicksort(nums):
    res = []
    for i in nums:
        has_found = False
        for j in range(len(res)):
            if res[j] >= i:
                has_found = True
                res.insert(j, i)
                break
        if not has_found:
            res.append(i)
    return res



if __name__ == '__main__':
    nums = [2,4,1,6,3,7,4]
    res = quicksort(nums)
    print(res)

    # dp[0] = 1
    # dp[1] = 2
    # dp[i] = dp[i-1] + dp[i-2]
    # return dp[n-1]

