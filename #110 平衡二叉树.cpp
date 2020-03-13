Tags: 递归, 二叉树, 简单
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/balanced-binary-tree
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
    bool res=true;
    bool isBalanced(TreeNode* root) {
        helper(root, 0);
        return res;
    }

    int helper(TreeNode* root, int lev){
        if(!root)
            return lev;
        if(res==false)
            return -1;
        int left = helper(root->left, lev+1);
        int right = helper(root->right, lev+1);
        lev = max(left, right);
        int dif = right>left ? right-left : left-right;
        if(dif>1){
            res=false;
            return -1;
        }
        return lev;
    }
};