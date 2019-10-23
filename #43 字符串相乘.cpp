class Solution {
public:
    string multiply(string num1, string num2) {
    string res="";
    int s1=num1.size()-1, s2=num2.size()-1;
    if(s1<0 || s2<0 || num1=="0" || num2=="0")
        return "0";
    double mul[s1+s2+2];
    for(int i=0; i<s1+s2+2;i++){
        mul[i]=0;
    }
    for(int i=s1; i>=0; i--){
        for(int j=s2; j>=0; j--){
            int temp = (num1[i]-'0') * (num2[j]-'0');
            temp += mul[i+j+1];
            mul[i+j] += temp/10;
            mul[i+j+1] = temp%10;
        }
    }
    
    
    for(int i=0; i<s1+s2+2; i++){
        if(i==0&&mul[i]==0)
            continue;
        res+=mul[i]+'0';
    }

    return res;
    }
};