class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = nums[0]+nums[1]+nums[2]-target;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            int l = i+1;
            int r = nums.size()-1;
            int fix = nums[i];
            while(l<r){
                int temp = fix+nums[l]+nums[r]-target;
                if(abs(temp) <= abs(diff))
                    diff = temp;
                if(temp<0)
                    l++;
                else if(temp>0)
                    r--;
                else if(temp==0)
                    return target;
            }
        }
        return diff+target;
        
    }
};