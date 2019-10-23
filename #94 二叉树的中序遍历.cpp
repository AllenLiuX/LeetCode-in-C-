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
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr)
            return res;
        if(root->left!=nullptr)
            inorderTraversal(root->left);
        res.push_back(root->val);
        if(root->right!=nullptr)
            inorderTraversal(root->right);
        return res;
    }
    
    
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *p;
        while(!s.empty()){
            while(p=s.top()){   //s.top()!=nullptr
                s.push(p->left);
            }
            s.pop();
            if(!s.empty()){
                p=s.top();
                s.pop();
                res.push_back(p->val);
                s.push(p->right);
            }
        }
        return res;
        
    }


};