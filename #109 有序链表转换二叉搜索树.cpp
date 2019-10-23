/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return nullptr;
        else if(!head->next)
            return new TreeNode(head->val);
        ListNode *p1 = head->next, *p2 = p1->next, *pre = head;
        while(p2 && p2->next){
            pre = pre->next;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        TreeNode* temp = new TreeNode(p1->val);
        ListNode* p3 = p1->next;
        p1 = nullptr; //不行！why？
        pre->next = nullptr;
        temp->left = sortedListToBST(head);
        temp->right = sortedListToBST(p3);
        return temp;
    }
};