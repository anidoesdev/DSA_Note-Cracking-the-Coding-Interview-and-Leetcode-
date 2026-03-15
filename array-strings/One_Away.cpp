```python
def one_away(str1, str2):
    if abs(len(str1) - len(str2)) > 1:
        return False
    count = 0
    first = str1 if len(str1) < len(str2) else str2
    second = str2 if len(str1) < len(str2) else str1
    
    i = 0
    j = 0
    while i < len(first) and j < len(second):
        if first[i] != second[j]:
            if count >= 1:
                return False
            count += 1
            if len(first) == len(second):
                i += 1
            else:
                j += 1
        else:
            i += 1
            j += 1
    return True


def main():
    str1 = "pale"
    str2 = "pal"

    print(one_away(str1, str2))

if __name__ == "__main__":
    main()
```