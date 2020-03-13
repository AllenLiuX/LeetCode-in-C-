给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/plus-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        int tag = 0;    //tag记录当前位加1后的结果
        while(i >= 0)   //判断数组是否遍历完成
        {
            tag = digits[i] + 1;
            digits[i--] = tag % 10;
            if(tag < 10)break;  //如果当前位加1后不需要进位，则停止遍历
        }
        //如果原数组首位加1结果大于10，需要进位
        if(i < 0 && tag >= 10)
            digits.insert(digits.begin(),1);  
        return digits;

//这个should work too！        
        // int s = digits.size()-1;
        // while(digits[s]==9)
        //     s--;
        // if(s==-1){
        //     digits.insert(digits.begin(),0);
        //     s=0;
        // }
        // digits[s]++;
        // s++;
        // while(s<digits.size()){
        //     digits[s]=0;
        //     s++;
        // }
        // return digits;
    }
};