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