Tags: 二叉树, 递归, 简单
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2.



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
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
    int dep=10000;
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        helper(root, 0);
        return dep;
    }

    void helper(TreeNode* root, int lev){
        if(!root)
            return;
        if(!root->left && !root->right){
            if(lev+1<dep)
                dep=lev+1;
        }
        helper(root->left, lev+1);
        helper(root->right, lev+1);
    }
};