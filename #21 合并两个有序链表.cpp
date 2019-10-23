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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // if(l1==nullptr && l2==nullptr)
        //     return nullptr;
        // ListNode* res = new ListNode(0);
        // ListNode* head = res;
        // while(l1!=nullptr || l2!=nullptr){
        //     if((l1!=nullptr&&l1->next!=nullptr) || (l2!=nullptr&&l2->next!=nullptr)){
        //         ListNode* node = new ListNode(0);
        //         res->next = node;
        //     }
        //     if(l1==nullptr){
        //         res->val=l2->val;
        //         l2=l2->next;
        //         // ListNode* node = new ListNode(0);
        //         // res->next = node;
        //         res=res->next;
        //         continue;
        //     }
        //     else if(l2==nullptr){
        //         res->val=l1->val;
        //         l1=l1->next;
        //         // ListNode* node = new ListNode(0);
        //         // res->next = node;
        //         res=res->next;
        //         continue;
        //     }
        //     else if(l1->val>=l2->val){
        //         res->val=l2->val;
        //         l2=l2->next;
        //         // ListNode* node = new ListNode(0);
        //         // res->next = node;
        //         res=res->next;
        //         continue;
        //     }
        //     else if(l2->val>l1->val){
        //         res->val=l1->val;
        //         l1=l1->next;
        //         // ListNode* node = new ListNode(0);
        //         // res->next = node;
        //         res=res->next;
        //         continue;
        //     }
        // }
        // res=nullptr;
        // return head;
        
        if(l1 == nullptr) 
            return l2;
        else if (l2 == nullptr) 
            return l1;
        else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }


    }
};