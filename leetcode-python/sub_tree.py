#coding=utf-8
import sys
#str = input()
#print(str)

class Node:
    def __init__(self, val):
        self.right = None
        self.left = None
        self.val =val
        # val is a string

def equal_tree(A, B):
    if not A and not B:
        return True
    elif not A or not B:
        return False
    if A.val != B.val:
        return False
    return equal_tree(A.left, B.left) and equal_tree(A.right, B.right)


def is_subtree(A, B):
    if equal_tree(A, B):
        return True
    if not A:
        return False
    return equal_tree(A.left, B) or equal_tree(A.right, B)


if __name__ == '__main__':
    pass

# O(n+m)的方法：preprocess，记录每个节点下面的节点数，只有当子节点数等于B时才比较。