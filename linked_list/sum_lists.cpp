```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def sum_list(head1, head2, carry):
    res = ListNode()
    value = carry
    if head1 is not None:
        value += head1.val
    if head2 is not None:
        value += head2.val
    res.val = value % 10
    if head1 is not None or head2 is not None:
        sum_node = sum_list(head1.next if head1 is not None else None, head2.next if head2 is not None else None, 1 if value >= 10 else 0)
        res.next = sum_node
    return res

def print_list(node):
    while node is not None:
        print(node.val, end='->')
        node = node.next
    print('NULL')

def main():
    head1 = ListNode(3)
    head1.next = ListNode(5)
    head1.next.next = ListNode(8)

    head2 = ListNode(3)
    head2.next = ListNode(5)
    head2.next.next = ListNode(8)

    print_list(sum_list(head1, head2, 0))

if __name__ == "__main__":
    main()
```