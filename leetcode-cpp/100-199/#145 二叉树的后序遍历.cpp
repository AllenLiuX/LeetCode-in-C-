Tags: 迭代, 二叉树, 遍历, 困难
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal
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