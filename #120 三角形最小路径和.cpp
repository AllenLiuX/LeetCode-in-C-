class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        for(int i=t.size()-2; i>=0; i--){
            for (int j = i; j>=0; j--){
                t[i][j] += min(t[i+1][j], t[i+1][j+1]);
            }   //动态规划，从下往上找min
        }
        return t[0][0];
    }
};