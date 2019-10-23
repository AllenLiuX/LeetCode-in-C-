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
    vector<int> Num;
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        Num = nums;
        return helper(0, nums.size()-1);
    }
    
    TreeNode* helper(int lo, int hi){
        if(lo>hi)
            return nullptr;
        int mid = lo + (hi-lo)/2;
        TreeNode* t = new TreeNode(Num[mid]);
        t->left = helper(lo, mid-1);
        t->right = helper(mid+1, hi);
        return t;
    }
};