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