class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //缩短边界法！ 不要用中间的i来变化，太麻烦！用边界缩减更直观！
        vector <int> ans;
        if(matrix.empty()) return ans; //若数组为空，直接返回答案
        int u = 0; //赋值上下左右边界
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while(true)
        {
            for(int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); //向右移动直到最右
            if(++ u > d) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
            for(int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); //向下
            if(-- r < l) break; //重新设定有边界
            for(int i = r; i >= l; --i) ans.push_back(matrix[d][i]); //向左
            if(-- d < u) break; //重新设定下边界
            for(int i = d; i >= u; --i) ans.push_back(matrix[i][l]); //向上
            if(++ l > r) break; //重新设定左边界
        }
        return ans;

        
        
    // vector<int> res;
    // if(matrix.size()==0)
    //     return res;
    // int i=0;
    // int n=matrix.size();
    // int m=matrix[0].size();
    // int depth=0;
    // int a=0,b=0,c=0,d=0;
    // while(i<n*m-1){
    //     a=depth;
    //     b=depth;
    //     c=depth;
    //     d=depth;
    //     while(a<m-1-depth){
    //         res.push_back(matrix[depth][a++]);
    //         i++;
    //     }
    //     while(b<n-1-depth){
    //         res.push_back(matrix[b++][m-1-depth]);
    //         i++;
    //     }
    //     if(i>=n*m-1)
    //         break;
    //     while(c<m-1-depth){
    //         res.push_back(matrix[n-1-depth][m-1-c]);
    //         c++;
    //         i++;
    //     }
    //     while(d<n-1-depth){
    //         res.push_back(matrix[n-1-d][depth]);
    //         i++;
    //         d++;
    //     }
    //     depth++;
    // }
    // if(m==n && m%2==1){
    //     res.push_back(matrix[depth][depth]);
    // }
    // else if(m>n)
    //     res.push_back(matrix[b][a]);
    // return res;
        
    }
};