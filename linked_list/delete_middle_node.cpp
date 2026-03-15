```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def delete_middle_node(head):
    temp = head
    count = 0
    while temp is not None:
        temp = temp.next
        count += 1
    prev = None
    temp = head
    for i in range(count // 2):
        prev = temp
        temp = temp.next
    if prev is not None:
        prev.next = temp.next
    else:
        head = head.next
    return head

def print_list(node):
    while node is not None:
        print(node.val, end='->')
        node = node.next
    print('NULL')

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    print_list(head)

    head = delete_middle_node(head)

    print_list(head)

if __name__ == "__main__":
    main()
```