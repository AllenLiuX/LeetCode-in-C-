class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        int m = a.size()-1;
        int n = b.size()-1;
        string res = "";
        if(m>n){
            for(int i=0; i<m-n; i++){
                b = '0' + b;
            }
        }
        if(m<n){
            for(int i=0; i<n-m; i++){
                a = '0' + a;
            }
        }//补位
        
        int s = m>n ? m:n;
        while(s>=0){
            int temp = (a[s]-'0')+(b[s]-'0')+carry;
            carry = temp/2;
            temp %= 2;
            char dig = temp+'0';
            res = dig + res;
            s--;
        } //从后往前加和进位
        if(carry>0) //处理最前一位
            res = '1'+res;
        
        return res;
    }
};