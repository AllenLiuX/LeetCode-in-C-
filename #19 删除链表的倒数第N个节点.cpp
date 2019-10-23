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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;
        while(n>0){
            first = first->next;
            n--;
        }
        while(first!=nullptr && first->next!=nullptr){
            first=first->next;
            second=second->next;
        }
        ListNode* temp = second->next;
        if(first == nullptr){   //special case!! when the deleted one is exactly the first node.
            head = head->next;
        }
        else if(temp!= nullptr){    //when the deleted one is in the mid of the list
            second->next = temp->next;
            delete temp;
        }
        else
            second->next = nullptr;
        return head;
    }
};