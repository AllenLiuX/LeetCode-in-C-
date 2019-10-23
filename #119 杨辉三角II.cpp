class Solution {
public:
    vector<int> res;
    vector<int> getRow(int rowIndex) {
        res.push_back(1);
        if(rowIndex<=0)
            return res;
        helper(rowIndex, 0);    //是0，因为第一层是0
        return res;
    }
    
    void helper(int rowIndex, int lev){
        if(rowIndex==lev)
            return;
        res.insert(res.begin(), 1);
        for(int i=1; i<res.size()-1; i++){  //从第2个到倒数第2个
            res[i] = res[i]+res[i+1];
        }
        // res.insert(res.begin(),1);
        helper(rowIndex, lev+1);
    }
};