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