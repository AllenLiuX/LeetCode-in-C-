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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next=head;
        ListNode *mp=head;
        int mm=m;
        while(mm>1){
            dummy = dummy->next;
            // mp=mp->next;
            mm--;
        }
        ListNode *pre=dummy->next;
        ListNode *cur=pre->next;
        ListNode *nex;
        if(cur!=nullptr)
            nex=cur->next;
        else
            nex=cur;    //此时dummy是m-1，pre是m，cur是m+1，nex是m+2
        while(n>m){
            cur->next=pre;
            pre=cur;
            cur=nex;
            if(nex!=nullptr)
                nex=nex->next;  //换方向后，所有向右平移1个
            n--;
        }
        dummy->next->next=cur;
        dummy->next=pre;    //首尾处理
        
        if(m>1)
            return head;
        else
            return dummy->next;
    }
};