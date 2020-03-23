Tags: 递归
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    vector<vector<int>> res;    //放在外面，以免每次重复递归！
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> pre;
        res.push_back(pre); //注意一开始空集也算一个！
        if(nums.size()<=0)
            return res;
        helper(nums, pre, 0, nums.size()-1);
        return res;
        
    }
    
    void helper(vector<int> nums, vector<int> pre, int begin, int end){
        if(nums.size() <= 0)
            return;
        for(int i=begin; i<=end; i++){
            pre.push_back(nums[i]);
            res.push_back(pre); //新的都要加入！
                helper(nums, pre, i+1, end);    //用begin和end双指针来滑动，避免改变nums
            pre.pop_back();
        }
    }
    
};