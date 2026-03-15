```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def return_element(head, k):
    count = 0
    temp = head
    while temp is not None:
        temp = temp.next
        count += 1
    temp = head
    for i in range(1, count - k + 1):
        temp = temp.next
    return temp.val

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    print(return_element(head, 2))

if __name__ == "__main__":
    main()
```