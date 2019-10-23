

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr = new ListNode(0);
        ListNode *p=l1, *q=l2, *result=ptr;
        int carry = 0;
//        bool overflow = false;
        while(p != nullptr || q != nullptr){
            int x = (p != nullptr) ? p->val : 0;
            int y = (q != nullptr) ? q->val : 0;
            int sum = x+ y + carry;
            carry = sum/10;
            ptr->next = new ListNode(sum % 10);
            ptr = ptr->next;
            if (p != nullptr)
                p = p->next;
            if (q != nullptr)
                q = q->next;
        }
        if (carry > 0) {
            ptr->next = new ListNode(carry);
        }

        return result->next;
    }
};