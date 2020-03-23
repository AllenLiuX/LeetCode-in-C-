Tags: 二维array, search
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
示例 1:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true
示例 2:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-a-2d-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n=matrix.size();
    if(n==0)
        return false;
    int m=matrix[0].size();
    if(n==1 && m==0)
        return false;   //空矩阵默认带一行n==1？？
    int l=0;
    int r=n-1;
    while(l<=r){    //当有mid+-1时，带等号
        int mid=l+(r-l)/2;
        if(matrix[mid][0] == target)
            return true;
        else if(m>0 && matrix[mid][0]<target && matrix[mid][m-1]>=target){
            l=mid;  //考虑正好在l这一行时，l不能在mid+1
            break;
        }
        else if(matrix[mid][0]<target)
            l=mid+1;
        else
            r=mid-1;
    }
    int p=l;
    if(p>n-1)   //考虑在最后一行时，上面l会超出bound
        p=n-1;
    l=0;
    r=m-1;
    while(l<=r){    //标准binary sort
        int mid=l+(r-l)/2;
        if(matrix[p][mid]==target)
            return true;
        else if(matrix[p][mid]<target)
            l=mid+1;
        else
            r=mid-1;
    }
    return false;
    }
};