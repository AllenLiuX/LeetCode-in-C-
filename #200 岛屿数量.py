Tags: 中等, stack, python
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:

输入:
11110
11010
11000
00000

输出: 1
示例 2:

输入:
11000
11000
00100
00011

输出: 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        direction = [[0,1],[1,0],[0,-1],[-1,0]]
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        if n == 0:
            return 0
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    res += 1
                    stack = [[i, j]]
                    while len(stack)!=0:
                        temp = stack.pop()
                        for k in direction:
                            newi = temp[0]+k[0]
                            newj = temp[1]+k[1]
                            if newi>=0 and newi<m and newj>=0 and newj<n and grid[newi][newj] == '1':
                                stack.append([newi, newj])
                                grid[newi][newj] = '0'
        return res