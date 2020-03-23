Tags: 构造, 递归, 简单
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 3
输出: [1,3,3,1]
进阶：

你可以优化你的算法到 O(k) 空间复杂度吗？



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pascals-triangle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    vector<int> res;
    vector<int> getRow(int rowIndex) {
        res.push_back(1);
        if(rowIndex<=0)
            return res;
        helper(rowIndex, 0);    //是0，因为第一层是0
        return res;
    }
    
    void helper(int rowIndex, int lev){
        if(rowIndex==lev)
            return;
        res.insert(res.begin(), 1);
        for(int i=1; i<res.size()-1; i++){  //从第2个到倒数第2个
            res[i] = res[i]+res[i+1];
        }
        // res.insert(res.begin(),1);
        helper(rowIndex, lev+1);
    }
};