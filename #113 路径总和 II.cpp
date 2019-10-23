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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)
            return res;
        vector<int> pres;
        helper(root, sum, 0, pres);
        return res;
    }
    
    void helper(TreeNode* root, int sum, int pre, vector<int> pres){
        if(!root)
            return;
        pres.push_back(root->val);
        if(!root->left && !root->right){
            if(pre+root->val==sum){
                res->push_back(pres);
                return;
            }
        }

        helper(root->left, sum, pre+root->val, pres);
        helper(root->right, sum, pre+root->val, pres);
    }
};