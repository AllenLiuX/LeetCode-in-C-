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