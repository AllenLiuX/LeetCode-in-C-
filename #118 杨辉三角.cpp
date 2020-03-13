Tags: 构造, 递归, 简单
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pascals-triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> generate(int numRows) {
        if(numRows<=0)
            return res;
        vector<int> v(1,1);
        res.push_back(v);
        helper(numRows, 1);
        return res;
    }

    void helper(int numRows, int lev){
        if (numRows==lev)
            return;
        vector<int> v(1,1);
        for(int i=0; i<res[lev-1].size()-1; i++){
            v.push_back(res[lev-1][i]+res[lev-1][i+1]);
        }
        v.push_back(1);
        res.push_back(v);
        helper(numRows, lev+1);
    }
};