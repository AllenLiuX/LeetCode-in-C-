from operator import itemgetter

def overlap(I):
    F = sorted(I, key=itemgetter(0))
    res = dc(F)
    return res

def dc(I):
    if len(I) == 1:
        return 0
    if len(I) == 2:
        if I[0][1]>I[1][0]:
            return I[0][1]-I[1][0]
        else:
            return 0
    left = I[0 : int(len(I)/2)]
    right = I[int(len(I)/2) : len(I)]
    l = dc(left)
    r = dc(right)
    large_r = 0
    for i in left:
        if i[1]>large_r:
            large_r = i[1]
    overl = 0
    for i in right:
        if i[0]>large_r:
            break
        if i[1]<large_r and i[1]-i[0]>overl:
            overl = i[1]-i[0]
        elif i[1]>=large_r and large_r-i[0]>overl:
            overl = large_r-i[0]
    return max(l, r, overl)


I = [[1,6], [2,7], [6,8]]
I2 = [[1,6],[2,5],[5,8]]
print(overlap(I))
