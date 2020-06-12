

def query(a):
    return len(set(a))

def partition(L):
    uniq = 0
    res = []
    hash = {}
    for i in range(0, len(L)):
        if query(L[:i+1]) != uniq:
            res.append([L[i], [i]])
            uniq+=1
            hash[L[i]] = len(res)-1
        else:
            l = 0
            r = i-1
            while l <= r:
                mid = l + int((r-l)/2)
                if query([L[mid], L[i]]) == 1:
                    break
                elif query(L[l:mid]) == query(L[l:mid]+[L[i]]):
                    r = mid-1
                elif query(L[mid:r]) == query(L[mid:r]+[L[i]]):
                    l = mid+1
            res[hash[L[mid]]][1].append(i)
    return res

a = [1,2,4,2,5,3,4]
b = [1,1,1, 3, 5, 3, 3, 1, -1, 4]

print(partition(a))
print(partition(b))

