Tags: 链表, 未解, 中等, 特殊, 双指针
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

 

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。


示例 2：

输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。


示例 3：

输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。


 

进阶：
你是否可以不用额外空间解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
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
 
