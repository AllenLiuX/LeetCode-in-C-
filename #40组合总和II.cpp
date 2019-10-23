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