# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def countNodes(self, root: TreeNode) -> int:
        temp = root
        if root == None:
            return 0
        depth = 0
        while temp != None: #find the depth of the complete tree
            temp = temp.right
            depth += 1
        cur = 0
        temp = root
        level = depth
        while temp != None:
            bot = temp.left
            for i in range(level-1):
                bot = bot.right
            if bot.right != None:
                temp = temp.right
            elif bot.left == None:
                temp = temp.left
            else:
                pass
