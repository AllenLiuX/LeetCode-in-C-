Tags: 递归, 二维array, 中等
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

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

