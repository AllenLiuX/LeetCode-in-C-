Tags: 链表
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *p1=head, *p2=head->next;
        while(p2!=nullptr){
            if(p2->val == p1->val){
                p2 = p2->next;
            }
            else{
                p1->next = p2;
                p1 = p2;
                p2 = p2->next;
            }
        }
        p1->next=nullptr;   //处理尾部，因为p2到最后并不会有新的val等于p1
        return head;
    }
};

//第二种更快

ListNode* deleteDuplicates(ListNode* head) {
    ListNode *p = new ListNode(0);  //dummy node？用于一般化头部的特殊情况，找到适当的head
    p->next = head;
    head = p;
    ListNode *p1, *p2;  //分别为左右两个节点，用于比较
    while(p->next){
        p1=p->next;
        p2=p1;
        while(p2->next && p2->next->val == p1->val){    //直到找到右边不等于左边
            p2 = p2->next;
        }
        if(p1!=p2)
            p->next = p2; //如果p->next = p2, 则为83题，保留重复的节点
        else
            p = p->next;
    }
    return head->next;
}