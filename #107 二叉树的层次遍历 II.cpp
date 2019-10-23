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
	vector<vector<int>> res = {};

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
        	return res;
        helper(root, 0);
        reverse(res.begin(),res.end());
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

//迭代
class Solution {
    public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;
    
        stack< vector<int> > svi;  //利用stack先进后出的特点，实现自底向上
        queue<TreeNode*> q; 
        q.push(root);
        while(!q.empty()){
            vector<int> vec_tmp;
            int q_size = q.size();
            for(int i=0; i<q_size; i++){
                TreeNode* p = q.front();
                q.pop();
                vec_tmp.push_back(p->val);
                if(p->left)  q.push(p->left);
                if(p->right) q.push(p->right);
            }
            svi.push(vec_tmp);
        }
        
        while(!svi.empty()){
            res.push_back(svi.top());
            svi.pop();
        }
        
        return res;
    }
};


class Solution 
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> res;//结果
        if(root==NULL) 
            return res;
        
        queue<TreeNode*> q;//定义一个队列，用来放树
        q.push(root);//先把整棵树放进去
        while(!q.empty())
        {
            vector<int> temp;//临时变量
            int len = q.size();//队列的长度（队列中树的个数）
            for(int i=0;i<len;i++)
            {
                TreeNode* now = q.front();//获取队列的第一个
                q.pop();//队列弹出
                temp.push_back(now->val);//临时变量保存第一颗树的根节点
                if(now->left!=NULL) //左子树非空
                    q.push(now->left);
                if(now->right!=NULL)//右子树非空 
                    q.push(now->right);
            }
            res.insert(res.begin(), temp);//将临时变量保存到结果中(从前面插入)
        }
        return res;
    }
};

