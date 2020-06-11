from operator import itemgetter

def overlap(I):
    F = sorted(I, key=itemgetter(0))
    res = 0
    for i in range(1, len(F)):
        if F[i][1] <= F[i-1][1]:
            if F[i][1]-F[i][0] > res:
                res = F[i][1]-F[i][0]
            F.remove(F[i])
    temp = dc(F)
    if temp > res:
        res = temp
    return res

def dc(I):
    if len(I) == 1:
        return 0
    if len(I) == 2:
        return I[0][1]-I[1][0]
    l = dc(I[0 : int(len(I)/2)])
    r = dc(I[int(len(I)/2) : len(I)])
    return max(l, r, I[int(len(I)/2)-1][1] - I[int(len(I)/2)][0])


I = [[1,6], [2,7], [6,8], [2,8]]
print(overlap(I))
