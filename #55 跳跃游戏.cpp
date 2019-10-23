class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>=n)
            {
                n=1;
            }
            else
            {
                n++;
            }
            if(i==0&&n>1)
            {
                return false;
            }
        }
        return true;
    }
};