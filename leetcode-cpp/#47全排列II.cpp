给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        backtrack(nums,res,0);
        return res;
    }
    

     void backtrack(vector<int> &nums,vector<vector<int>> &res,int i){
         if(i==nums.size())
             res.push_back(nums);
         for(int j=i;j<nums.size();j++){
             bool conti=false;
             for(int k=i; k<j; k++){    //从i到j，只要有哪个和第j个一样，就会在更深层出现同样的结果。参照【1，1，2，2】
                 if(nums[k]==nums[j]){
                     conti=true;
                     break;
                 }
             }
             if(conti)
                 continue;
             // if(i!=j && nums[j]==nums[i])
             //     continue;   //这只是swap两个相同的一种情况
             swap(nums[i],nums[j]);
             backtrack(nums,res,i+1);
             swap(nums[i],nums[j]);
         }
     }
};