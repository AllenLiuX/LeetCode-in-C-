class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        int mid;
        while(l<=r){
            mid = l+(r-l)/2;
            if(mid>0 && nums[mid]<nums[mid-1]){
                return nums[mid];
            }
            if(mid<nums.size()-1 && nums[mid]>nums[mid+1])
                return nums[mid+1];
            if(nums[mid]<nums[r]){ //分界点在左边
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return nums[mid];
    }
};