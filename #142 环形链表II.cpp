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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head, *p2 = head;
        bool hasCycle = false;
        if(!head || !head->next)
            return nullptr;
        while (p2->next && p2->next->next) {
            p = p->next;
            p2 = p2->next->next;
            if (p == p2) {
                hasCycle = true;
                break;
            }
        }

        // 步骤二：若有环，找到入环开始的节点
        if (hasCycle) { 
            ListNode *q = head;
            while (p != q) { //一定能在入口碰到？？数学分析？
                p = p->next;
                q = q->next;
            }
            return q;
        } 
        else 
            return nullptr;
        }
};

//数学分析
2⋅distance(tortoise)=distance(hare)
2(F+a)=F+a+b+a
2F+2a=F+2a+b
F=b
​	
 
