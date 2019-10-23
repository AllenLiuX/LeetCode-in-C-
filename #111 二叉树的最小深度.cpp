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