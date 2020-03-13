Tags: 特殊, 动态规划, 中等
给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) 
            return 0;
        int ret, pos, neg, temp;
        pos = nums[0];
        neg = nums[0];
        ret = nums[0];
        for(int i = 1; i < nums.size(); i++){
            temp = pos;
            pos = max(nums[i], max(pos * nums[i], neg * nums[i]));
            neg = min(nums[i], min(temp * nums[i], neg * nums[i]));
            ret = max(pos, ret);
        }
        return ret;
    }
};