Tags: 链表
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-list
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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* p1 = new ListNode(0), *p2 = new ListNode(0);  //dummy nodes
        ListNode *p = head, *res = p1, *tail = p2;  //可以不用p，直接用head来操作
        while(p){
            ListNode *temp = new ListNode(p->val);
            if(p->val < x){
                p1->next = temp;
                p1 = p1->next;
            }
            else{
                p2->next = temp;
                p2 = p2->next;
                }
            p = p->next;
        }
        p1->next = tail->next;  //p1永远指着第一组的最后一个node，而不是nullptr
        //为什么p1 = tail->next;的时候就一点都接不上？？
        return res->next;
    }
};