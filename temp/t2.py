import sys

def dfs(cur_n, cur_p, p, used, a, b):
    if cur_n == 0:
        return
    for i in range(n):
        if used[i]:
            continue
        if n - a[i] >= 0:
            n = n - a[i]
        cur_p += b[i]
        if cur > p:
            return
        used[i] = 1
    dfs(n, cur, p, used, a, b)

# def findp(m, n, p, costs, values):



if __name__ == "__main__":
    t = int(sys.stdin.readline().strip())
    for _ in range(t):
        m, n, p = sys.stdin.readline().split()
        m, n, p = int(m), int(n), int(p)
        nums = sys.stdin.readline()
        a = list(map(int, nums.split()))
        nums = sys.stdin.readline()
        b = list(map(int, nums.split()))
        used = []
        for i in range(m):
            used.append(0)
        # res = dfs(n, 0, p, used, costs, values)
        def dfs(cur_n, cur_p):
            global count
            if cur_n == 0:
                return
            for i in range(m):
                if used[i]:
                    continue
        res = dfs(n, 0)

        print(res)