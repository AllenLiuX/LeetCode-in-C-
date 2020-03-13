Tags: 递归, 二叉树
给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

示例:

输入: 3
输出:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释:
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
            return vector<TreeNode*>{};
        return helper(1,n);
    }
    
    //先默认完成底层的，然后看当前层的。左边一大堆，右边一大堆，排列组合后pushback每一组
    vector<TreeNode*> helper(int begin, int end){
        vector<TreeNode*> res;
        if(begin>end){  //左边没有和右边没有的时候，给左/右边放一个nullptr
            res.push_back(nullptr);
            return res;
        }
        
        for(int i=begin; i<=end; i++){
            vector<TreeNode*> lef = helper(begin, i-1);
            vector<TreeNode*> righ = helper(i+1, end);
            for(auto l : lef){
                for(auto r : righ){
                    TreeNode *temp = new TreeNode(i);
                    temp->left = l;
                    temp->right = r;
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};