编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
---

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // string out="";
        // bool match=true;
        // if(strs.size()==0)
        //     return "";
        // for(int i=0; match; i++){
        //     char k=strs[0][i];
        //     for(string a : strs){
        //         if(a[i]!=k){
        //             match=false;
        //             break;
        //         }
        //     }
        //     if(!match)
        //         break;
        //     out+=k; 
        // }
        // return out;
        
        if (strs.size() == 0) 
            return "";
        string prefix = strs[0];    //先取第一个作为标准，之后跟每一个比较，只要末尾字母不相同就直接删掉
        for (int i = 1; i < strs.size(); i++){
            while (strs[i].substr(0,prefix.size()) != prefix) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix=="") 
                    return "";
            }
       }        
    return prefix;

    }
};