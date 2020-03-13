Tags: 二叉树, 迭代, 递归, stack, 遍历, 中等
给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal
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