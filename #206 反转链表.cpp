Tags: 链表
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

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