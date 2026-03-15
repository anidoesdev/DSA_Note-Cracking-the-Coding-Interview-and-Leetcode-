```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def find_intersection(head1, head2):
    mp = {}
    while head1:
        mp[head1] = 1
        head1 = head1.next
    while head2:
        if head2 in mp:
            return head2
        head2 = head2.next
    return None

def insert_node(node, val):
    new_node = ListNode(val)
    if not node:
        node = new_node
        return node
    temp = node
    while temp.next:
        temp = temp.next
    temp.next = new_node
    return node

def print_list(node):
    while node:
        print(node.val, end='->')
        node = node.next
    print('NULL')

def main():
    head = None
    head = insert_node(head, 1)
    head = insert_node(head, 3)
    head = insert_node(head, 1)
    head = insert_node(head, 2)
    head = insert_node(head, 4)
    head1 = head
    head = head.next.next.next
    head_sec = None
    head_sec = insert_node(head_sec, 3)
    head2 = head_sec
    head_sec = head_sec.next
    head_sec.next = head

    print_list(head1)
    print_list(head2)

    res = find_intersection(head1, head2)
    print(res.val)

if __name__ == "__main__":
    main()
```