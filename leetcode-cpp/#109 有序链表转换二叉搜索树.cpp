Tags: 二叉树, 递归, 中等
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

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