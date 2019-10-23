class Solution {
public:
    int numTrees(int n) {   //动态规划，思路来自于某点的方法数取决于左边和右边，而左右两边的数量已计算过，相乘取排列组合即可。
        if(n<2)
            return 1;
        int dp[n+1] = {};
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3; i<n+1; i++){
            for(int j=0; j<i; j++){
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};  //1,1,2,5,14