def subset(nums):
    n = len(nums)
    ind = [[]]
    for i in range(n):
        temp = []
        for j in ind:
            temp += [j+[0], j+[1]]
        ind = temp
    print(ind)
    res = []
    for i in ind:
        res.append([m for m,n in zip(nums, i) if n])
    print(res)



subset([1,2,3])
    