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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB, *tail=nullptr;
        if(!p1 || !p2)
            return nullptr;
        while(p1!=p2){  //一圈圈走，迟早会相遇
            if(!p1->next){
                tail = p1;
                p1 = headA;
            }
            else
                p1 = p1->next;
            if(!p2->next){
                if(tail!=nullptr && p2!=tail)   //p1标记tail，p2看是不是一样
                    return nullptr;
                p2 = headB;
            }
            else
                p2 = p2->next;
        }
        return p1;
    }
};