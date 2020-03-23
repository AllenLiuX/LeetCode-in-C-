给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-ii
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
                if(i!=begin && cand[i-1]==cand[i])  //相同数字在深度上被考虑，而横向应该去重。
                        continue;
                if(sum+cand[i] <=tar){
                    pres.push_back(cand[i]);
                    helper(cand, tar, sum+cand[i], i+1, pres, ori);   //找i以后的，因为前面的找过了or不符合要求
                    pres.pop_back();    //这一个cand[i]检测完后把它从pres拿出来
                }
            }
        }
    }

    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end()); //sorting helps to remove the duplicates!
        helper(candidates, target, 0, 0, tmp, res);
        return res;
    }
};