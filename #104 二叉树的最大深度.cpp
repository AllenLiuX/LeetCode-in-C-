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
	int max=0;
    int maxDepth(TreeNode* root) {
        if(!root)
        	return max;
        helper(root, 1);
        return max;
    }

    void helper(TreeNode* root, int lev){
    	if(!root)
    		return;
    	if(lev>max)
    		max=lev;
    	helper(root->left,lev+1);
    	helper(root->right, lev+1);

    }
};