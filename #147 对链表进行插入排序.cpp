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
    ListNode* insertionSortList(ListNode* head) {
    	if(!head || !head->next)
    		return head;
        ListNode* p=head;   //主看p->next, 所以从第二个开始
        ListNode* dum = new ListNode(INT_MIN);  //处理要换head的情况
        dum->next = head;
        while(p->next){
        	ListNode *pre = dum;// *post=p->next->next;
        	ListNode* cur = p->next;
        	while(pre!=p){
        		if(pre->next->val > cur->val){
        			p->next=cur->next;  //去掉cur
        			cur->next = pre->next;  //插入cur在pre之后
        			pre->next = cur;
        			break;
        		}
        		pre = pre->next;
        	}
        	if(pre==p)  //如果cur没被换走
	        	p=p->next;
        }
        return dum->next;
    }
};