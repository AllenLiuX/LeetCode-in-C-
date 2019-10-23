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