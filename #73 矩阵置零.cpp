class Solution {
public:
    //更好的方法是使用不重复的存储方法，保证行和列各有唯一性，在设置0的时候也可以节省时间了
    void setZeroes(vector<vector<int>>& matrix) {
    vector<pair<int, int>> zeros;
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j]==0){
                pair<int, int> temp = {i,j};
                zeros.push_back(temp);
            }
        }
    }
    for(int i=0; i<zeros.size(); i++){
        int a=zeros[i].first;
        int b=zeros[i].second;  //0的坐标（a,b)
        for(int p=0; p<n; p++){ //从上到下
            matrix[p][b] = 0;
        }
        for(int q=0; q<m; q++){
            matrix[a][q] = 0;
        }
    }

    }
};