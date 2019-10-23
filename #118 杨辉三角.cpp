class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> generate(int numRows) {
        if(numRows<=0)
            return res;
        vector<int> v(1,1);
        res.push_back(v);
        helper(numRows, 1);
        return res;
    }

    void helper(int numRows, int lev){
        if (numRows==lev)
            return;
        vector<int> v(1,1);
        for(int i=0; i<res[lev-1].size()-1; i++){
            v.push_back(res[lev-1][i]+res[lev-1][i+1]);
        }
        v.push_back(1);
        res.push_back(v);
        helper(numRows, lev+1);
    }
};