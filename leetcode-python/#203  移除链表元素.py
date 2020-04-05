Tags: 简单, 链表, python
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
---

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        if head == None:##same
            return head
        while head!=None and head.val == val:   #每次调用前一定要确认对象不是None，尤其是对象一直在变的时候
            head = head.next
        if head == None or head.next == None: ##same
            return head
        cur = head
        while cur!=None and cur.next != None: ##same
            while cur.next != None and cur.next.val == val: ##same
                cur.next = cur.next.next
            cur = cur.next
        return head