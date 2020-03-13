给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

---

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        int max=0;
        string result="";
        // if(s.size()==1)
        //     return s;
        for(int i=0; i<length; i++){
            for(int j=0; j<=i; j++){//检查aba型，从中间到两边，直到左右不相等
                if((i+j)>=length || s[i-j]!=s[i+j]){
                    break;
                }
                if(2*j+1>max){
                    max=2*j+1;
                    result=s.substr(i-j, max);
                }
            }
            for(int k=0; k<=i; k++){//检查abba型
                if((i+k+1)>length || s[i-k]!=s[i+k+1]){
                    break;
                }
                if(2*k+2>max){
                    max=2*k+2;
                    result=s.substr(i-k, max);
                }
            }
        }
        return result;
    }
};