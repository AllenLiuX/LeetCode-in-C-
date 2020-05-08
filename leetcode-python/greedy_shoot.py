from operator import itemgetter

def shooter(I):
    F = sorted(I, key=itemgetter(1))
    X = []
    last = -1
    for i in F:
        if i[0] >= last:
            X.append(i[1]-0.5)
            last = i[1]-0.5
    return X


# I = [[1,0,2], [2,2,7], [3,1,3], [4,6,9], [5,0,4], [6,8,9]]
I = [[0,2], [2,7], [1,3], [6,9], [0,4], [8,9]]
I2 = [[0,1],[1,2],[4,5],[3,6], [7,8],[4,6]]
print(shooter(I))
print(shooter(I2))
