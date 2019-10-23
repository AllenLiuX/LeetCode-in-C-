class Solution {
public:
    int myAtoi(string str) {
        int out=0;
        bool hasfound=false;
        int sign = 1;
        for(char c : str){
            int digit = c-'0';
            if(hasfound){
                if(!isdigit(c))
                    break;
            }
            if(c=='-'){
                hasfound=true;
                sign=-1;
                continue;
            }
            if(c=='+'){
                hasfound=true;
                continue;
            }
            if(!hasfound){
                if(isspace(c))
                    continue;
                if(!isdigit(c))
                    return 0;
            }
            hasfound = true;
            if(out>INT_MAX/10 || (out ==INT_MAX/10 && digit>7))
                return INT_MAX;
            if(out<INT_MIN/10 ||(out == INT_MIN/10 && digit>8))
                return INT_MIN;
            out = out*10 + digit*sign;
        }
        return out;
    }
};