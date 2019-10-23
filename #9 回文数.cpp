class Solution {
public:
    bool isPalindrome(int x) {
        // if(x<0)
        //     return false;
        // int size=to_string(x).size();
        // if(size==1)
        //     return true;
        // int up=x/(pow(10, size-1));
        // if(up!=(x%10))
        //     return false;
        // int y = (x-up*pow(10, size-1))/10;
        // if(size>3 && y<10 && y>0)
        //     return false;
        // return isPalindrome(y);
        
        
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        return x == revertedNumber || x == revertedNumber / 10;

    }
};