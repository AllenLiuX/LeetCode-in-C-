class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s=="")
            return 0;
        int i=s.size()-1;
        while(s[i]==' ')
            i--;
        int end = i;
        while(s[i]!=' ' && i>=0)
            i--;
        return end-i;
    }
};