```python
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def remove_dups(head):
    st = set()
    prev = None
    while head is not None:
        if head.val in st:
            prev.next = head.next
        else:
            st.add(head.val)
            prev = head
        head = head.next

def using_two_pointer(head):
    slow = head
    while slow is not None:
        fast = slow
        while fast.next is not None:
            if fast.next.val == slow.val:
                fast.next = fast.next.next
            else:
                fast = fast.next
        slow = slow.next

def print_list(node):
    while node is not None:
        print(node.val, end='->')
        node = node.next
    print('NULL')

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(2)
    head.next.next.next = ListNode(3)
    head.next.next.next.next = ListNode(4)

    print_list(head)

    using_two_pointer(head)

    print_list(head)

if __name__ == "__main__":
    main()
```