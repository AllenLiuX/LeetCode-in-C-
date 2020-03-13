Tags: 二叉树, 递归, 深度优先
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-search-tree
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
    int* last = NULL;   //思路，遍历顺序为从小到大！左中右。
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;

        if(!isValidBST(root->left)) 
            return false;
        
        if (last && *last>=root->val) //每次这时的last都是上一个被考虑的，比如root为中间时，last为它左边的最右边；root为右边时，last为它上一个中间
            return false;
        
        last = &root->val;
        if(!isValidBST(root->right)) 
            return false;
        return true;
    }
};