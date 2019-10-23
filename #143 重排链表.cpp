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