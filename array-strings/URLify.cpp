```python
def URLify(s, n):
    space_count = 0
    for i in range(n):
        if s[i] == ' ':
            space_count += 1
    index = n + space_count * 2
    s = list(s)
    for i in range(n - 1, -1, -1):
        if s[i] == ' ':
            s[index - 1] = '0'
            s[index - 2] = '2'
            s[index - 3] = '%'
            index -= 3
        else:
            s[index - 1] = s[i]
            index -= 1
    return ''.join(s)


def main():
    s = "Mr John Smith    "
    n = 13
    print(URLify(s, n))


if __name__ == "__main__":
    main()
```