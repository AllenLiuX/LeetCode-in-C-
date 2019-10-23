/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//hash法，easy

//快慢指针法（参照运动员套圈）
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode *fast=head->next, *slow=head;
        while(fast && slow){
            if(fast == slow)
                return true;
            slow = slow->next;
            if(fast->next)
                fast = fast->next->next;
            else
                return false;
        }
        return false;   
    }
};