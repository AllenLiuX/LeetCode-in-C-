Tags: 递归
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combinations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n<=0 || k<=0 || n<k)
            return res;
        vector<int> pre = {};
        helper(n, k, 1, pre, res);
        return res;
    }
    
    void helper(int n, int k, int begin, vector<int> pre, vector<vector<int>>& res){
        if(pre.size()==k){
            res.push_back(pre);
            return;
        }
        if(n-begin+1<k-pre.size())  //剪枝！左边为剩下可选的数量，+1是因为n和begin相等时仍然有一个；右边是还需选择的数量
            return;
        for(int i=begin; i<=n; i++){
            pre.push_back(i);
            helper(n, k, i+1, pre, res);
            pre.pop_back();
        }
    }
};