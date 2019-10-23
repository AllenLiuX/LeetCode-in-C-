class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        int m=-1, n=-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                m=mid, n=mid;
                while(m>=0 && nums[m]==target){
                    m--;
                }
                while(n<nums.size() && nums[n]==target){
                    n++;
                }
                vector<int> res = {m+1,n-1};
                return res;
            }
            if(nums[mid]<nums[r]){ //分界点在左边
                if(nums[mid]<target && target<=nums[r]){
                    l=mid+1;
                }
                else
                    r=mid-1;
            }
            else{
                if(nums[mid]>target && target>=nums[l]){
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
        }
        vector<int> res = {-1,-1};
        return res;
    }
};