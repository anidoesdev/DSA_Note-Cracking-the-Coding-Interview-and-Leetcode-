```python
class StackMin:
    def __init__(self):
        self.st1 = []
        self.st2 = []

    def push(self, value):
        if not self.st2 or value <= self.st2[-1]:
            self.st2.append(value)
        self.st1.append(value)

    def pop(self):
        if not self.st1:
            return -1
        value = self.st1.pop()
        if value == self.st2[-1]:
            self.st2.pop()
        return value

    def min(self):
        if not self.st2:
            return float('inf')
        return self.st2[-1]

def main():
    super_stack = StackMin()
    super_stack.push(2)
    super_stack.push(1)
    super_stack.push(4)
    super_stack.push(10)
    super_stack.push(11)
    print(super_stack.min())
    print(super_stack.pop())
    print(super_stack.min())

if __name__ == "__main__":
    main()
```