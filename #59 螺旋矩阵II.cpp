给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0) return {{}};
        vector<vector<int> > res(n,vector<int>(n,0));
        int down=0,up=n-1,left=0,right=n-1;
        int itm=1;
        while(left<=right && down<=up){
            for(int i=left;i<=right;i++) 
                res[down][i]=itm++;
            for(int i=down+1;i<=up;i++) 
                res[i][right]=itm++;
            for(int i=right-1;i>=left;i--) 
                res[up][i]=itm++;
            for(int i=up-1;i>=down+1;i--) 
                res[i][left]=itm++;
            down++;
            up--;
            left++;
            right--;
        }
        return res;
    }
};