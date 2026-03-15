```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def partition(head, partition):
    start = head
    end = head
    while head is not None:
        temp = head.next
        if head.val < partition:
            head.next = start
            start = head
        else:
            end.next = head
            end = head
        head = temp
    end.next = None
    return start

def print_list(node):
    while node is not None:
        print(node.val, end='->')
        node = node.next
    print('NULL')

def main():
    head = ListNode(3)
    head.next = ListNode(5)
    head.next.next = ListNode(8)
    head.next.next.next = ListNode(5)
    head.next.next.next.next = ListNode(10)
    head.next.next.next.next.next = ListNode(2)
    head.next.next.next.next.next.next = ListNode(1)

    print_list(head)
    start = partition(head, 5)
    print_list(start)

if __name__ == "__main__":
    main()
```