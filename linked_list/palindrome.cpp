```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverse(head):
    temp = None
    while head is not None:
        n = ListNode(head.val)
        n.next = temp
        temp = n
        head = head.next
    return temp

def is_palindrome(head, reverse_head):
    while head is not None and reverse_head is not None:
        if head.val != reverse_head.val:
            return False
        head = head.next
        reverse_head = reverse_head.next
    return True

def main():
    head = ListNode(0)
    head.next = ListNode(1)
    head.next.next = ListNode(2)
    head.next.next.next = ListNode(1)
    head.next.next.next.next = ListNode(0)

    node = head
    rev = reverse(head)

    print(is_palindrome(node, rev))

if __name__ == "__main__":
    main()
```