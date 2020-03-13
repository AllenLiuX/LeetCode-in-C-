Tags: array, search
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // unordered_set<int> dict(nums.begin(),nums.end());
        // return dict.count(target);
        
        int l = 0, r = nums.size()-1;
        while(l<=r){
            //处理重复数字
            while(l<r&&nums[l]==nums[l+1]) 
                l++;
            while(l<r&&nums[r]==nums[r-1]) 
                r--;
            int mid = l+(r-l)/2;
            if(nums[mid]==target || nums[l]==target || nums[r]==target) 
                return true;
            //左半部分有序
            if(nums[mid]>=nums[l]){
                if(target<nums[mid]&&target>nums[l]) //不能等于，因为已被排除
                    r = mid-1;//target落在左半边
                else 
                    l = mid+1;
            }
            else{//右半部分有序
                if(target>nums[mid]&&target<nums[r]) 
                    l = mid+1;//target落在右半边
                else 
                    r = mid-1;
            }
        }
        return false;
    }
};