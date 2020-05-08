def visit(V, E):
    indegree = {}
    for v in V:
        indegree[v] = 0
    for e in E:
        indegree[e[1]] += 1
    S = []
    T = []
    for (n, d) in indegree.items():
        if d==0:
            S.append(n)
    while len(S)!=0:
        for i in S:
            T.append(i)
            for j in E:
                if j[0] == i:
                    indegree[j[1]] -= 1
                    if indegree[j[1]] == 0:
                        S.append(j[1])
            S.remove(i)
    if len(T) != len(V):
        return False


    for i in range(len(T)-1):
        if [T[i], T[i+1]] not in E:
            return False
    return True


V = [1,2,3,4,5,6,7,8,9]
E = [[1,2],[2,3],[1,4],[2,5],[5,4],[5,8],[4,7],[7,8],[8,9],[9,6],[6,3]]
E2 = [[2,3],[1,4],[2,5],[5,4],[5,8],[4,7],[7,8],[8,9],[9,6],[6,3]]
print(visit(V,E))
print(visit(V,E2))