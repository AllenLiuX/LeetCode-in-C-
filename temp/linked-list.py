
class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next

def find_common(head1, head2):
    cur1 = head1
    cur2 = head2
    len1 = 0
    len2 = 0
    while cur1 != None:
        len1 += 1
        cur1 = cur1.next

    while cur2 != None:
        len2 += 1
        cur2 = cur2.next

    cur1 = head1
    cur2 = head2
    while len1 > len2:
        cur1 = cur1.next
        len1 -= 1
    while len2 > len1:
        cur2 = cur2.next
        len2 -= 1

    res = cur1
    while cur1 != None:
        if cur1.data != cur2.data:
            res = cur1.next
        cur1 = cur1.next
        cur2 = cur2.next
    return res


if __name__ == '__main__':





