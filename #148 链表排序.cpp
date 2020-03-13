Tags: 链表, 排序, 递归, 中等
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

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

