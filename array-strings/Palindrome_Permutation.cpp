```python
def permutation_of_palindrome(s):
    char_count = {}
    for char in s:
        if char in char_count:
            char_count[char] += 1
        else:
            char_count[char] = 1

    odd_count = 0
    for count in char_count.values():
        if count % 2 != 0:
            odd_count += 1
        if odd_count > 1:
            return False
    return True

str = "tactcoa"
print(permutation_of_palindrome(str))
```