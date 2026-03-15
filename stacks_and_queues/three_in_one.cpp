```python
class FlexibleMultiStack:
    def __init__(self):
        self.stacks = []

    def push(self, value, stack_num):
        if stack_num >= len(self.stacks):
            self.stacks.extend([[] for _ in range(stack_num - len(self.stacks) + 1)])
        self.stacks[stack_num].append(value)

    def pop(self, stack_num):
        if stack_num >= len(self.stacks) or not self.stacks[stack_num]:
            return -1
        return self.stacks[stack_num].pop()

    def top(self, stack_num):
        if stack_num >= len(self.stacks) or not self.stacks[stack_num]:
            return -1
        return self.stacks[stack_num][-1]

    def is_empty(self, stack_num):
        if stack_num >= len(self.stacks):
            return True
        return not self.stacks[stack_num]


class FixedMultiStack:
    def __init__(self, stack_size, num_stacks):
        self.stack_size = stack_size
        self.num_stacks = num_stacks
        self.values = [0] * (stack_size * num_stacks)
        self.sizes = [0] * num_stacks

    def push(self, value, stack_num):
        if self.is_full(stack_num):
            return
        self.sizes[stack_num] += 1
        self.values[self.index_of_top(stack_num)] = value

    def pop(self, stack_num):
        if self.is_empty(stack_num):
            return -1
        top_index = self.index_of_top(stack_num)
        value = self.values[top_index]
        self.values[top_index] = 0
        self.sizes[stack_num] -= 1
        return value

    def top(self, stack_num):
        if self.is_empty(stack_num):
            return -1
        return self.values[self.index_of_top(stack_num)]

    def index_of_top(self, stack_num):
        offset = stack_num * self.stack_size
        size = self.sizes[stack_num]
        return offset + size - 1

    def is_empty(self, stack_num):
        return self.sizes[stack_num] == 0

    def is_full(self, stack_num):
        return self.sizes[stack_num] == self.stack_size


def main():
    st = FixedMultiStack(5, 3)
    st.push(5, 1)
    st.push(6, 1)
    st.push(1, 1)
    st.push(3, 1)
    st.push(4, 1)
    st.push(10, 2)
    print(st.pop(1))
    print(st.top(2))
    print(st.top(1))

    st_flexible = FlexibleMultiStack()
    st_flexible.push(5, 1)
    st_flexible.push(6, 1)
    st_flexible.push(1, 1)
    st_flexible.push(3, 1)
    st_flexible.push(4, 1)
    st_flexible.push(10, 2)
    print(st_flexible.pop(1))
    print(st_flexible.top(2))
    print(st_flexible.top(1))


if __name__ == "__main__":
    main()
```