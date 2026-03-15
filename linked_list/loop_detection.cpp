```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def loop_detection(head):
    slow = head
    fast = head

    while fast is not None and fast.next is not None:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            break
    if fast is None or fast.next is None:
        return None
    slow = head
    while slow != fast:
        slow = slow.next
        fast = fast.next
    return fast

def print_list(node):
    while node is not None:
        print(node.val, end='->')
        node = node.next
    print('NULL')

def main():
    head = ListNode(1)
    head.next = ListNode(3)
    head.next.next = ListNode(4)
    head.next.next.next = ListNode(5)
    head.next.next.next.next = head.next
    res = loop_detection(head)
    print(res.val)

if __name__ == "__main__":
    main()
```