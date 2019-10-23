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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* n1 = head;
        head = head->next;
        ListNode* temp=head->next;
        head->next=n1;
        // n1->next=temp;
        ListNode* tail = swapPairs(temp);
        n1->next=tail;  //链表recursion记得把新的后面的放在对的位置！
        return head;
    }
};