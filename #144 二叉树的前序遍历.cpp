/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //递归
class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return res;
        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return res;
    }
};

//迭代。更快
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> q; //先处理深的，用stack而不是queue。queue的话就是横向遍历了。
        if(!root)
            return res;
        TreeNode* p;
        q.push(root);
        while(!q.empty()){
            p = q.top();
            res.push_back(p->val);
            q.pop();
            if(p->right)
                q.push(p->right);
            if(p->left)
                q.push(p->left);
        }
        return res;
    }
};