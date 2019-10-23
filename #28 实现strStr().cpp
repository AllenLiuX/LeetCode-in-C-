class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="")
            return 0;
        if(haystack.size()<needle.size())
            return -1;
        for(int i=0; i<haystack.size()-needle.size()+1; i++){   //+1, in order to match haystack's tail
            if(haystack[i]==needle[0]){
                string temp = haystack.substr(i, needle.size());
                if(temp == needle){
                    return i;
                }
            }
        }
        return -1;
    }
};