def search(a):
    r = int(len(a)-1)
    l = int(0)
    while l<=r:
        mid = l + int(int((r-l))/2)
        if a[mid] == mid:
            return mid
        elif a[mid] < mid:
            l = mid+1
        else:
            r = mid-1
    return -1


    
a=[1,2,3,3,4,7,8,9]
b=[-5,-4,1,2,3,5,9,11]
print(search(a))
print(search(b))