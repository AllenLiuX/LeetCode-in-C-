class Solution {
public:
    bool isMatch(string s, string p) {
        if (p[0]=='\0') {
        return s[0] == '\0';
    }
    //p's length 1 is special case 
    if (p[1] == '\0' || p[1] !='*' ) {
        if (s[0]=='\0' || ( p[0] !='.' && s[0] != p[0] )) {
            return false;
        }
        return isMatch(s.substr(1), p.substr(1));
    }
    int len = s.size();
    int i = -1;
    while (i < len && (i <0 || p[0]=='.' || p[0]==s[i])){
        if (isMatch(s.substr(i+1), p.substr(2))) {
            return true;
        }
        i++;
    }
    return false;
        
    }
};