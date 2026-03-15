```python
class MyQueue:
    def __init__(self):
        self.st1 = []
        self.st2 = []

    def shift_stack(self):
        if not self.st2:
            while self.st1:
                self.st2.append(self.st1.pop())

    def push(self, value):
        self.st1.append(value)

    def peek(self):
        self.shift_stack()
        return self.st2[-1]

    def remove(self):
        self.shift_stack()
        return self.st2.pop()


queue = MyQueue()
queue.push(1)
queue.push(2)
queue.push(3)
queue.push(4)
print(queue.peek())
queue.remove()
print(queue.peek())
```