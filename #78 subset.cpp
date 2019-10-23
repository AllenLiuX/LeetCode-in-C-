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