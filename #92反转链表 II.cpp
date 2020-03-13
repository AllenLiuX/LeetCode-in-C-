Tags: 链表
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next=head;
        ListNode *mp=head;
        int mm=m;
        while(mm>1){
            dummy = dummy->next;
            // mp=mp->next;
            mm--;
        }
        ListNode *pre=dummy->next;
        ListNode *cur=pre->next;
        ListNode *nex;
        if(cur!=nullptr)
            nex=cur->next;
        else
            nex=cur;    //此时dummy是m-1，pre是m，cur是m+1，nex是m+2
        while(n>m){
            cur->next=pre;
            pre=cur;
            cur=nex;
            if(nex!=nullptr)
                nex=nex->next;  //换方向后，所有向右平移1个
            n--;
        }
        dummy->next->next=cur;
        dummy->next=pre;    //首尾处理
        
        if(m>1)
            return head;
        else
            return dummy->next;
    }
};