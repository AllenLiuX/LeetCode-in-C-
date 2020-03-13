Tags: 遍历, 简单
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    bool isPalindrome(string s) {
        int l=0, r=s.size()-1;
        while(l<r){
            while(l<s.size() && !isalnum(s[l])) //审题！包含数字。而tolower并不会改变数字。
                l++;
            while(r>=0 && !isalnum(s[r]))
                r--;
            if(l>r) //考虑中间只有符号的情况
                return true;
            if(tolower(s[l])!=tolower(s[r]))
                return false;
            l++, r--;
        }
        return true;
    }
};