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
	vector<vector<int>> res = {};

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
        	return res;
        helper(root, 0);
        return res;
    }

    void helper(TreeNode* root, int lev){
    	if(!root)   //base case
    		return;
    	if(res.empty() || res.size()-1<lev){    //需要加empty，不然溢出，因为empty的时候size为1，最开始并不会创建。
    		vector<int> temp = {root->val};
    		res.push_back(temp);
    	}
    	else
    		res[lev].push_back(root->val);
    	helper(root->left, lev+1);
    	helper(root->right, lev+1);
    }
};