/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    TreeNode* curr;
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        curr = root;
        while (!s.empty())
            s.pop();
    }

    /** @return the next smallest number */
    int next() {
        if (hasNext()) {
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }   //stack先push中间，再push左边的
            curr = s.top();
            s.pop();//用过了就去掉
        } else {
            return -1;
        }
        int res = curr->val;
        curr = curr->right; //
        return res;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty() || curr != NULL;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */