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
    ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head; //从后往前，默认已处理好。再处理当前（最前面）这个
    ListNode *p = reverseList(head->next);  //p为最低层的p，也就是最后一个node。
    head->next->next = head;    //此时head->next的next本来已经是nullptr了
    head->next = nullptr;   
    return p;
    }
};

//迭代
class Solution {
public:
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
};