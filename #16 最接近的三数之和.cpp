给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
---

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