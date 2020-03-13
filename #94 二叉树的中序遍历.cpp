Tags: 二叉树
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
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