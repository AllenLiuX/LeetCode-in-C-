class Solution {
public:
    int numDecodings(string s) {    //动态规划，找条件，填数！
        int len = s.size();
        int dp[len+1] = {};
        dp[len] = 1;
        if(s[len-1]=='0')
            dp[len-1]=0;
        else
            dp[len-1]=1;    //处理头两项
        for(int i=len-2; i>=0; i--){    //到下一步取决于这步本身是否为零且和上一步能否组成<26
            int a = s[i]-'0';
            int b = s[i+1]-'0';
            if(a==0)
                dp[i]=0;
            else if(a*10+b<=26)
                dp[i]=dp[i+1]+dp[i+2];
            else
                dp[i]=dp[i+1];
        }
        return dp[0];
        
        
    }
};