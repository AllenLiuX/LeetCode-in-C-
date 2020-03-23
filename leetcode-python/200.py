from typing import List

direction = [[0,1],[1,0],[0,-1],[-1,0]]
def numIslands(grid: List[List[str]]) -> int:
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





a = [[1,1,0,0,0],[1,1,0,0,0],[0,0,1,0,0],[0,0,0,1,1]]
for i in range(len(a)):
    for j in range(len(a[0])):
        a[i][j] = str(a[i][j])
print(a)
print(numIslands(a))