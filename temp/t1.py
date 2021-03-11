import sys


def findk(k, num):
    if len(num) == 0:
        return k
    elif len(num) == 1:
        return num[0]+k
    remains = k
    cur = num[0]
    for i in num[1:]:
        if cur+1 != i:
            gap = i - (cur+1)
            if gap >= remains:
                return cur + remains
            else:
                remains -= gap
        cur = i
    return num[-1] + remains



if __name__ == "__main__":
    t = int(sys.stdin.readline().strip())
    for _ in range(t):
        n, k = sys.stdin.readline().split()
        n, k = int(n), int(k)
        nums = sys.stdin.readline()
        values = list(map(int, nums.split()))
        # print(values)
        # print(type(values))
        res = findk(k, values)
        print(res)