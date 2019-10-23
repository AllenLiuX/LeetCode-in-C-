class Solution {
public:
vector<vector<int>> helper(vector<int> nums, int target, vector<vector<int>>& ori, int first){
    sort(nums.begin(),nums.end());
    if(nums.empty())
        return ori;
    for(int i=0; i<nums.size(); i++){
        int fix=nums[i]-target;
        if(fix>-target)
            break;
        if(i>0 && fix == nums[i-1])
            continue;
        int l=i+1, r=nums.size()-1;
        while(l<r){
            if(nums[l]+nums[r]==-fix){
                if(l==i+1 || r==nums.size()-1){
                    ori.push_back(vector<int> {nums[i],nums[l],nums[r], first});
                    l++;
                    r--;
                }
                else if(nums[l]==nums[l-1])//左指针直接移到下一个不同的。
                    l++;
                else if(nums[r]==nums[r+1])
                    r++;
                else{
                    ori.push_back(vector<int> {nums[i],nums[l],nums[r], first});
                    l++;
                    r--;
                }
            }
            else if(nums[l]+nums[r]>-fix)
                r--;
            else
                l++;
        }
    }
    return ori;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res={};
    // vector<int> nums2;
    if(nums.size()<4)
        return res;
    sort(nums.begin(),nums.end());
    // nums2.push_back(nums[0]);
    // for(int i=1; i<nums.size(); i++){
    //     if(nums[i]!=nums[i-1])
    //         nums2.push_back(nums[i]);
    // }
    int former=-9999;
    while(!nums.empty()){
        int back =nums.back();
        if(back==former){
            nums.pop_back();
            continue;
        }
        former=back;
        int tar = target-back;
        nums.pop_back();
        res = helper(nums, tar, res, back);
    }
    return res;
}
};