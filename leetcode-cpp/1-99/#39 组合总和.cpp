给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
示例 2:

输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    void helper(vector<int>& cand, int tar, int sum, int begin, vector<int>& pres, vector<vector<int>>& ori){
        if(sum==tar){
            ori.push_back(pres);
        }
        else{
            for(int i=begin; i<cand.size(); i++){
                if(sum+cand[i] <=tar){
                    pres.push_back(cand[i]);
                    helper(cand, tar, sum+cand[i], i, pres, ori);   //找i以后的，因为前面的找过了or不符合要求
                    pres.pop_back();
                }
            }
        }
        
        // if(cand.size()==1){
        //     if(cand[0] == tar){
        //         pres.push_back(tar);
        //         ori.push_back(pres);
        //         return ori;
        //     }
        //     for(int i=0; i<cand.size(); i++){
        //         helper(cand, tar-cand[i], pres, ori);
        //     }
        //     return ori;
        // }
    }
        
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        helper(candidates, target, 0, 0, tmp, res);
        return res;
    }
};