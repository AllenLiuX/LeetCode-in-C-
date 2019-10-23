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
    bool res=false;
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        helper(root, sum, 0);
        return res;
    }
    
    void helper(TreeNode* root, int sum, int pre){
        if(!root)
            return;
        if(!root->left && !root->right){
            if(pre+root->val==sum){
                res=true;
                return;
            }
        }

        helper(root->left, sum, pre+root->val);
        helper(root->right, sum, pre+root->val);
    }
};