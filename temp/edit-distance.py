# coding=utf-8
import sys


# str = input()
# print(str)

def edit_distance(str_a, str_b):
    len_a = len(str_a)
    len_b = len(str_b)
    dp = [[0 for i in range(len_a)] for j in range(len_b)]
    for i in range(len_a):
        for j in range(len_b):
            if str_a[i] == str_b[j]:
                dp[j][i] = 0
            else:
                dp[j][i] = 1

    #    dp = [[0 for i in range(len_a)] for j in range(len_b)]
    #    for i in range(len_a):
    #        dp[0][i] = dist[0][i]
    #    for j in range(len_b):
    #        dp[j][0] = dist[j][0]
    for i in range(1, len_a):
        for j in range(1, len_b):
            dp[j][i] = min(dp[j - 1][i], dp[j - 1][i - 1], dp[j][i - 1]) + dp[j][i]

    return dp[len_b - 1][len_a - 1]


if __name__ == '__main__':
    res = edit_distance('abcdefg', 'acdfgh')
    print(res)