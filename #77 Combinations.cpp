class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n<=0 || k<=0 || n<k)
            return res;
        vector<int> pre = {};
        helper(n, k, 1, pre, res);
        return res;
    }
    
    void helper(int n, int k, int begin, vector<int> pre, vector<vector<int>>& res){
        if(pre.size()==k){
            res.push_back(pre);
            return;
        }
        if(n-begin+1<k-pre.size())  //剪枝！左边为剩下可选的数量，+1是因为n和begin相等时仍然有一个；右边是还需选择的数量
            return;
        for(int i=begin; i<=n; i++){
            pre.push_back(i);
            helper(n, k, i+1, pre, res);
            pre.pop_back();
        }
    }
};