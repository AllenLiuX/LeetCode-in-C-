Tags: 动态规划
一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

示例 1:

输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
示例 2:

输入: "226"
输出: 3
解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-ways
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

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