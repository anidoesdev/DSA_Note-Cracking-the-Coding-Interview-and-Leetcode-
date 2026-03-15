```python
def is_rotation(s1, s2):
    if len(s1) == len(s2) and len(s1) > 0:
        return s2 in s1 + s1
    return False

s1 = "waterbottle"
s2 = "erbottlewat"

print(is_rotation(s1, s2))
```