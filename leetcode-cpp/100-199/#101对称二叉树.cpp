Tags: 递归, 二叉树, 迭代, queue, 简单
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/symmetric-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

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