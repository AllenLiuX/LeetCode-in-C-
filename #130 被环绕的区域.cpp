class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;
        int r = board.size();
        int c = board[0].size();

        for(int i=0; i<r; i++){
            dfs(board, i, 0);
            dfs(board, i, c-1);
        }   //左右两侧

        for(int j=1; j<c-1; j++){
            dfs(board, 0, j);
            dfs(board, r-1, j);
        }   //上下两侧

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(board[i][j]=='1')
                    board[i][j]='O';    //审题，O不是0
                else
                    board[i][j]='X';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int m, int n) {
        int r = board.size();
        int c = board[0].size();
        if(m>=0 && m<r && n>=0 && n<c && board[m][n]=='O'){
            board[m][n] = '1';  //作为中间暂存标记。
            dfs(board, m+1, n); //顺着往里走，只要是O就标记，直到终止
            dfs(board, m-1, n);
            dfs(board, m, n+1);
            dfs(board, m, n-1);
        }
    }
};

