class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0, threes = 0;
        for(int num : nums){
            twos |= ones & num;
            ones ^= num;
            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;

    }
};


//三门电路法：a和b三次状态：00，01，10，00
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (auto x : nums) {
            b = (b ^ x) & ~a;   //第一次：原本b，a均为0，所以加上去b=x；第二次：b为x，a为0，所以b=0；第三次：b为0，a为x，所以,b^x为x，b=0
            a = (a ^ x) & ~b;   //第一次：b为x，所以a=0；第二次：b为0，a^x为x，所以a=x；第三次：b为0，a为x，所以a^x为0，a=0
        }
        return b;

    }
};

//注意：
// x ^ 0 = x;
// x ^ x = 0;
// x & ~x = 0;
// x & ~0 = x;