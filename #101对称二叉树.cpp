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

//递归法
    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
    
    bool helper(TreeNode* p, TreeNode* q){
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;
        if(p->val == q->val)
            return helper(p->left, q->right) && helper(p->right, q->left);
        return false;
    }
    
    
//迭代法（queue）
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode *t1=q.front();
            q.pop();
            TreeNode *t2=q.front();
            q.pop();
            if(!t1 && !t2)
                continue;
            if(!t1 || !t2)
                return false;
            if(t1->val!=t2->val)
                return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};