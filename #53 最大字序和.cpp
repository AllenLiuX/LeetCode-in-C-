class Solution {
public:
    int maxSubArray(vector<int>& nums) {    
        //动态规划写法
        if(nums.size()==0)
            return 0;
        int sum=-1;
        int res=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            sum = max(nums[i], sum+nums[i]);    //记sum，直到sum<0
            res = max(sum, res);
        }
        return res;
    }
};