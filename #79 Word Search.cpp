class Solution {
public:
    vector<vector<char>> Board;

    void cleaner(vector<vector<bool>>& v){  //记得加&
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v[0].size(); j++){
                v[i][j]=false;
            }
        }
    }

    bool helper(vector<vector<bool>>& visited, string word, int x, int y){
        if(word.size()<=0)
            return true;
        bool res = false;
        int xx[4] = {0, 1, 0, -1};
        int yy[4] = {-1, 0, 1, 0};  //用这个方法来统一四个方向
        for(int i=0; i<4; i++){
            int nx = x + xx[i];
            int ny = y + yy[i];
            if(nx>=0 && nx<Board[0].size() && ny>=0 && ny<Board.size() && !visited[ny][nx] && Board[ny][nx]==word[0]){
                visited[ny][nx]=true;
                res = helper(visited, word.substr(1), nx, ny);
                if(res)
                    return true;
                visited[ny][nx]=false;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        Board = board;  //不会变的大变量就放在func外面
        long n = board.size();
        long m = board[0].size();
        vector<bool> v(m, false);
        vector<vector<bool>> visited(n, v); //vector的初始化！n个，值为v
        cleaner(visited);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0]){
                    visited[i][j]=true;
                    bool res = helper(visited, word.substr(1), j, i);
                    if(res)
                        return true;
                    cleaner(visited);
                }
            }
        }
        return false;
    }
};