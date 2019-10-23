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
	vector<int> pre, in;    //不变的放外面就好，避免重复递归

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        in = inorder;
        return helper(0, pre.size()-1, 0, in.size()-1);
    }

    TreeNode* helper(int leftpre, int rightpre, int leftin, int rightin){
    	if(leftpre>rightpre || leftin>rightin)  //当上一层mid=leftin的时候，说明没有需要创建的，leftpre会大一个，所以return null
    		return nullptr;
    	int root = pre[leftpre];
    	int mid = leftin;	//mid 是inorder里面root的位置
    	for(int i=leftin; i<=rightin; i++){
    		if(in[i]==root){
    			mid=i;
    			break;
    		}
    	}
    	auto s = new TreeNode(root);
        // inorder: [mid-lo2, mid, hi2-mid]
        // preorder:[root, mid-lo2, hi2-mid]
    	s->left = helper(leftpre+1, leftpre+mid-leftin, leftin, mid-1); //mid-leftin+1是放左边的个数
    	s->right = helper(leftpre+mid-leftin+1, rightpre, mid+1, rightin);
    	return s;
    }
};