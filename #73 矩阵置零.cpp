Tags: 二维array
给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

示例 1:

输入: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2:

输入: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
进阶:

一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个常数空间的解决方案吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/set-matrix-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

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