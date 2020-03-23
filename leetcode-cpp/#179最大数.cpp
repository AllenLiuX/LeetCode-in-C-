Tags: 中等, 字符串, sort
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

示例 1:

输入: [10,2]
输出: 210
示例 2:

输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    static bool compare(int n1, int n2){
        if(!n1)
            return false;
        if(!n2)
            return true;    //防止overbufferflow！but why？？？
        string a = to_string(n1);
        string b = to_string(n2);
        // int size = a.size()>b.size() ? a.size() : b.size();
        // for(int i=0; i<size; i++){
        //     if(a[i%a.size()]>b[i%b.size()])
        //         return true;
        //     else if(a[i%a.size()]<b[i%b.size()])
        //         return false;
        // }
        return a+b > b+a ? true : false;    //简单的规则！直意表达！
        // return true;
    }

    string largestNumber(vector<int>& nums) {
        if(nums.size()<2)
            return to_string(nums[0]);  //只有1位时无法compare
        sort(nums.begin(), nums.end(), &compare);
        string res;
        bool allZero = true;
        for(int i : nums){
            res += to_string(i);
            if(i>0)
                allZero = false;
        }
        return allZero ? "0" : res; //注意是“0”，不是0！
    }
};