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