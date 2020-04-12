# Given a singly linked list, determine if it is a palindrome.
#
# Example 1:
#
# Input: 1->2
# Output: false
# Example 2:
#
# Input: 1->2->2->1
# Output: true
# Follow up:
# Could you do it in O(n) time and O(1) space?


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        slow = head
        fast = head
        prev = None
        flag = True
        # step1: reverse
        while(fast and fast.next):
            fast = fast.next.next
            temp = slow.next
            slow.next = prev
            prev = slow
            slow = temp
        # step2: compare
        if fast: # 奇数
            node1 = prev
            node2 = slow.next
        else: # 偶数
            node1 = prev
            node2 = slow
        while(node1 and node2):
            if node1.val != node2.val:
                flag = False
            node1, node2 = node1.next, node2.next
        # step3: recover(optional)
        back = slow
        while(prev):
            temp = prev.next
            prev.next = back
            back = prev
            prev = temp
        return flag