class Solution {
public:
    int reverse(int x) {
        // string in = to_string(x);
        // int size = in.size();
        // if(x<0)
        //     size--;
        // if(size>=10)
        //     return 0;
        int out=0;
        // int down=pow(10,size-1); 
        // int up=1;
        while(x!=0){
            int digit=x%10;
            x/=10;
            if(out>INT_MAX/10 || (out == INT_MAX/10 && digit > 7))
                return 0;
            if(out<INT_MIN/10 ||(out == INT_MIN/10 && digit < -8))
                return 0;
            out = out*10 + digit;
        }
        return out;
        
        // int rev = 0;
        // while (x != 0) {
        //     int pop = x % 10;
        //     x /= 10;
        //     if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        //     if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
        //     rev = rev * 10 + pop;
        // }
        // return rev;

    }
};

