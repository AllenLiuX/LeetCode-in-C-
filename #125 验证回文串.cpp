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