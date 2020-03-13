Tags: 二叉树, 递归, 构造, 中等
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
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
	vector<int> post, in;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post = postorder;
        in = inorder;
        return helper(0, in.size()-1, 0, post.size()-1);
    }

    TreeNode* helper(int lo1, int hi1, int lo2, int hi2){
    	if(lo1>hi1 || lo2>hi2)
    		return nullptr;
    	int root = post[hi2];
    	int mid = lo1;
    	for(int i=lo1; i<=hi1; i++){
    		if(in[i]==root){
    			mid=i;
    			break;
    		}
    	}
    	auto s = new TreeNode(root);

    	s->left = helper(lo1, mid-1, lo2, lo2+mid-lo1-1);   //mid-lo1-1是多出来的左边的个数
    	s->right = helper(mid+1, hi1, lo2+mid-lo1, hi2-1);
    	return s;
    }
};