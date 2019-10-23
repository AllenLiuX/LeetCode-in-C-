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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> q; //先处理深的，用stack而不是queue。queue的话就是横向遍历了。
        if(!root)
            return res;
        TreeNode* p;
        q.push(root);
        while(!q.empty()){
            p = q.top();
            res.insert(res.begin(), p->val);
            q.pop();
            if(p->left)
                q.push(p->left);    //左边是最深的，所以也最后insert到最前面
            if(p->right)
                q.push(p->right);
        }
        return res;

    }
};