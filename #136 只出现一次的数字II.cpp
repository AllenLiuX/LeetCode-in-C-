Tags: bits, 中等, 构造
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,3,2]
输出: 3
示例 2:

输入: [0,1,0,1,0,1,99]
输出: 99

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

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