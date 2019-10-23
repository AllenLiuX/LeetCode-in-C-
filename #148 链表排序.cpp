class Solution {
public:
    ListNode* sortList(ListNode* node) {
        if(!node || !node->next) 
            return node;
        ListNode *fast=node;//快指针走两步
        ListNode *slow=node;//慢指针走一步
        ListNode *brek=node;//断点
        while(fast && fast->next)
        {
            fast=fast->next->next;
            brek=slow;
            slow=slow->next;
        }
        brek->next=nullptr;
        ListNode *l1=sortList(node);
        ListNode *l2=sortList(slow);
        return merge(l1,l2);
    }

    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        if(l1==NULL)
        {
            return l2;
        }
        if(l2==NULL)
        {
            return l1;
        }
        if(l1->val < l2->val)   //只有当l1和l2都是有序链表的时候，这么合并才能也是有序的。
        {
            l1->next=merge(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next=merge(l2->next,l1);
            return l2;
        }
    }
};

