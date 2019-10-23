class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        if(r==0)
            return 0;
        while(l<r){
            int mid = l+(r-l)/2;
            if((mid==0 || nums[mid]>nums[mid-1]) && nums[mid]>nums[mid+1])  //mid一开始有可能是0
                return mid;
            else if (nums[mid]>nums[mid+1])
                r=mid-1;
            else
                l=mid+1;
        }
        return r;   //最后l不小于r了（两端的情况）一定是l或者r
    }
};