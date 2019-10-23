class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int, int>> col(9), row(9), box(9);
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                int n = (i/3)*3 + j/3;  //the # of box
                int cur = board[i][j]-'0';
                if(board[i][j]=='.')
                    continue;
                if(col[j][cur] || row[i][cur] || box[n][cur]){
                    return false;
                }
                
                col[j][cur] = 1;
                row[i][cur] = 1;
                box[n][cur] = 1;
            }
        }
        return true;
    }
};