Tags: 二叉树, 递归, 中等
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
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
	vector<vector<int>> res = {};

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
        	return res;
        helper(root, 0);
        return res;
    }

    void helper(TreeNode* root, int lev){
    	if(!root)   //base case
    		return;
    	if(res.empty() || res.size()-1<lev){    //需要加empty，不然溢出，因为empty的时候size为1，最开始并不会创建。
    		vector<int> temp = {root->val};
    		res.push_back(temp);
    	}
    	else
    		res[lev].push_back(root->val);
    	helper(root->left, lev+1);
    	helper(root->right, lev+1);
    }
};