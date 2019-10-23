class Solution {
public:
    int trailingZeroes(int n) {
        long a=5;
        int res = 0;
        while(n/a > 0){ //看有多少个5的倍数，25的倍数，125的。。。
            res += n/a;
            a *= 5;
        }
        return res;
    }
};