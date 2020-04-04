Tags: 链表, 构造, 中等
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorder-list
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
    void reorderList(ListNode* head) {
    	if(!head || !head->next)
    		return;
        ListNode *pre = new ListNode(0);
        pre->next=head;
        ListNode *slow=head, *fast=head;
        while(fast && fast->next){
            pre=pre->next;
        	slow = slow->next;
        	fast = fast->next->next;
        }
        ListNode *mid = reverseList(slow);
        pre->next=nullptr;  //得把前面的尾部变了，不然永远走不出来。
        merge(head, mid);
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *pre=head, *cur=head->next, *nex=head->next->next;
        while(nex){
            cur->next=pre;
            pre=cur;
            cur=nex;
            nex=nex->next;
        }
        cur->next=pre;
        head->next=nullptr;
        return cur;
    }

    ListNode* merge(ListNode* p1, ListNode* p2){
    	ListNode *temp1, *temp2;
        ListNode *head = p1;
    	while(p1 && p2){
    		temp1 = p1->next;
    		temp2 = p2->next;
    		p1->next = p2;
            if(temp1)   //important! 不然长度不一的话容易丢最后一个！
        		p2->next=temp1;
    		p1=temp1;
    		p2=temp2;
    	}
        return head;
    }
};