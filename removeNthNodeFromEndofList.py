class Solution:
    def removeNthFromEnd(self, head, n: int):
        ptr1 = head
        if head.next == None and n == 1:
            return None
        for i in range(n):
            ptr1 = ptr1.next
        if ptr1 == None:
            head = head.next
        ptr2 = head
        prev = None
        while ptr1 != None:
            prev = ptr2
            ptr1 = ptr1.next
            ptr2 = ptr2.next
        if prev != None:
            prev.next = ptr2.next
        return head