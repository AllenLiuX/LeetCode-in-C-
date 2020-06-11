dp = {}

def opt(w, l, S):
    if (w,l) in dp:
        return dp[(w,l)]
    res = w*l
    for i in S:
        if i[0]<=w and i[1]<=l:
            temp = min(opt(w-i[0], l, S)+opt(i[0], l-i[1], S), opt(w, l-i[1], S)+opt(w-i[0], i[1], S))
            if temp<res:
                res = temp
    dp[(w, l)] = res
    return res

def main():
    S = [(10,4), (9,8), (6,2), (7,5), (15,10)]
    for i in S:
        dp[i] = 0
    print(opt(21, 11, S))

main()
