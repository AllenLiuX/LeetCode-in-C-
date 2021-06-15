# coding=utf-8
import sys
# str = input()
# print(str)
import math
import random


def generator():
    a = random.random()
    b = random.random()

    r = a

    theta = 2 * math.pi * b
    prob = a

    ret = False
    c = random.random()
    if c <= prob:
        ret = True

    # 或者直接用 a = math.sqrt(a), 来表示概率。

    if ret:
        return r * math.cos(theta), r * math.sin(theta)
    else:
        return False