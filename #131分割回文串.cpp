Tags: 中等, 递归, 字符串
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    vector<vector<string>> res;
    string str;
    vector<vector<string>> partition(string s) {
        str = s;
        vector<string> pre;
        dfs(0, pre);
        return res;
    }

    void dfs(int pos, vector<string> pre){
        if(pos>=str.size())
            res.push_back(pre);
        for(int i=1; i<=str.size()-pos; i++){
            if(isp(str.substr(pos, i))){
                pre.push_back(str.substr(pos, i));
                dfs(pos+i, pre);
                pre.pop_back(); //记得pop
            }
        }
    }


    bool isp(string s){
        int l=0, r=s.size()-1;
        while(l<r){
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};