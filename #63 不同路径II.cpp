一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？



网格中的障碍物和空位置分别用 1 和 0 来表示。

说明：m 和 n 的值均不超过 100。

示例 1:

输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: 2
解释:
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    // int helper(vector<vector<int>>& ob, int a, int b){
//         int m=ob.size(), n=ob[0].size();
//         if(m<=0 || n<=0)
//             return 0;
//         // else if(m==1 || n==1)
//         //     return 1;
//         if(ob[m-1][n-1]==1 || ob[0][0]==1)
//             return 0;
//         if(a==m-1 && b==n-1)
//             return 1;
//         int path=0;
//         if(a<m-1 && ob[a+1][b]==0)
//             path += helper(ob, a+1, b);
//         if(b<n-1 && ob[a][b+1]==0)
//             path += helper(ob, a, b+1);
//         return path;
//     }
    
    
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         return helper(obstacleGrid, 0, 0);
//     }
        
        
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {      
        int w = obstacleGrid.size();
        if(w == 0 ) return 0;
        int h = obstacleGrid[0].size();
        long long  dp[w][h];
        dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for(int i = 1;i< w;++i){
            dp[i][0]  =  obstacleGrid[i][0] == 1 ? 0 : dp[i-1][0];
        }
        for(int j = 1;j< h;++j){
            dp[0][j]  =  obstacleGrid[0][j] == 1 ? 0 : dp[0][j-1];
        }
        for(int i = 1;i< w;++i){
            for(int j = 1;j<h;++j){
                dp[i][j]  =  obstacleGrid[i][j] == 1 ? 0 : dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[w-1][h-1];      
    }


 

};