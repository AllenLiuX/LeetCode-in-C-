class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v((1<<n),0);    //1<<n 就是2^n
        for(int i=1<<n; i--; v[i]=i^(i>>1));
        return v;
    }
};