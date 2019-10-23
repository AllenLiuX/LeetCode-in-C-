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