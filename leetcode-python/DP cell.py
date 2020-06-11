from operator import itemgetter

def opt(C, d, cost, pos):
    if d==1:
        cost += (1-pos)*len(C)
        return cost, [C]
    if len(C) == 0:
        return cost, []
    res = opt(C[1:], d-1, cost+(1-pos), pos+C[0][1])
    cut = 1
    for i in range(2, len(C)):
        pos2 = pos
        for j in range(0, i):
            pos2 += C[j][1]
        temp = opt(C[i:], d-1, cost+i*(1-pos), pos2)
        if temp[0]<res[0]:
            res = temp
            cut = i
    res[1].insert(0, C[:cut])
    return res



C0 = [[1,0.2],[2,0.2],[3,0.2],[4,0.2],[5,0.2]]
C = sorted(C0, key=itemgetter(1), reverse=True)
# print(C)
print(opt(C, 2, 0, 0))

C0 = [[1,0.5],[2,0.7],[3,0.2],[4,0.4]]
C = sorted(C0, key=itemgetter(1), reverse=True)
print(opt(C, 2, 0,0))