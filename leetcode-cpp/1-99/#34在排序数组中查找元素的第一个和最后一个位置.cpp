给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

---

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