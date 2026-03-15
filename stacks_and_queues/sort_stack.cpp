```python
class Stack:
    def __init__(self):
        self.stack = []

    def push(self, item):
        self.stack.append(item)

    def pop(self):
        if not self.is_empty():
            return self.stack.pop()
        return None

    def top(self):
        if not self.is_empty():
            return self.stack[-1]
        return None

    def is_empty(self):
        return len(self.stack) == 0


def sort_stack(st):
    sort_st = Stack()
    while not st.is_empty():
        temp = st.pop()
        while not sort_st.is_empty() and sort_st.top() > temp:
            st.push(sort_st.pop())
        sort_st.push(temp)
    while not sort_st.is_empty():
        st.push(sort_st.pop())
    return st


def print_stack(st):
    temp_st = Stack()
    while not st.is_empty():
        temp = st.pop()
        print(temp)
        temp_st.push(temp)
    while not temp_st.is_empty():
        st.push(temp_st.pop())


def main():
    st = Stack()
    st.push(5)
    st.push(4)
    st.push(3)
    st.push(2)
    st.push(1)
    st.push(6)

    st = sort_stack(st)
    print_stack(st)


if __name__ == "__main__":
    main()
```