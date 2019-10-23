class Solution {
public:
    int titleToNumber(string s) {
    	int sum=0;
        for(char c : s){
            int cur = c-'A'+1;  //防溢出
        	sum = sum*26 + cur;
        }
        return sum;
    }
};