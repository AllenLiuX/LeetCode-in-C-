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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
            return vector<TreeNode*>{};
        return helper(1,n);
    }
    
    //先默认完成底层的，然后看当前层的。左边一大堆，右边一大堆，排列组合后pushback每一组
    vector<TreeNode*> helper(int begin, int end){
        vector<TreeNode*> res;
        if(begin>end){  //左边没有和右边没有的时候，给左/右边放一个nullptr
            res.push_back(nullptr);
            return res;
        }
        
        for(int i=begin; i<=end; i++){
            vector<TreeNode*> lef = helper(begin, i-1);
            vector<TreeNode*> righ = helper(i+1, end);
            for(auto l : lef){
                for(auto r : righ){
                    TreeNode *temp = new TreeNode(i);
                    temp->left = l;
                    temp->right = r;
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};