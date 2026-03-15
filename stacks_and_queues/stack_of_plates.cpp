```python
class MultiStack:
    def __init__(self, capacity):
        self.st = []
        self.capacity = capacity
        self.curr = -1

    def push(self, value):
        if self.curr == -1 or len(self.st[self.curr]) == self.capacity:
            self.st.append([value])
            self.curr += 1
            print("new stack created")
            return
        self.st[self.curr].append(value)

    def pop(self):
        if self.curr > -1:
            if len(self.st[self.curr]) > 0:
                res = self.st[self.curr].pop()
                if len(self.st[self.curr]) == 0:
                    self.st.pop()
                    self.curr -= 1
                    print("stack deleted")
                return res
        return -1


def main():
    super_stack = MultiStack(5)
    super_stack.push(1)
    super_stack.push(2)
    super_stack.push(3)
    super_stack.push(4)
    super_stack.push(5)
    super_stack.push(6)
    super_stack.push(7)
    print(super_stack.pop())


if __name__ == "__main__":
    main()
```