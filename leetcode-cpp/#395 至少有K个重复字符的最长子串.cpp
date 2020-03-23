Tags: 中等, map, 递归, 分治
找到给定字符串（由小写字符组成）中的最长子串 T ， 要求 T 中的每一字符出现次数都不少于 k 。输出 T 的长度。

示例 1:

输入:
s = "aaabb", k = 3

输出:
3

最长子串为 "aaa" ，其中 'a' 重复了 3 次。
示例 2:

输入:
s = "ababbc", k = 2

输出:
5

最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:

int Max = 0;
int longestSubstring(string s, int k) {
    if(s=="")
        return 0;
    unordered_map<char, int> dic;
    for( char c : s){
        dic[c]++;
    }

    unordered_map<char,int>::iterator iter= dic.begin();
    bool done = true;
    for(;iter !=dic.end();iter++){
        if(iter->second < k)
            done = false;
    }
    if(done){
        if(s.size()>Max){
            Max = s.size();
            return Max;
        }
        else
            return Max;
    }
    string temp = "";
    vector<string> strs;
    for( int i=0; i<s.size(); i++ ){
        if(dic[s[i]]>=k)
            temp += s[i];
        else if(temp!=""){
            strs.push_back(temp);
            temp = "";
        }
        if(i==s.size()-1 && temp!="")
            strs.push_back(temp);
    }
    for(string str : strs){
        longestSubstring(str, k);
    }
    return Max;
}


};