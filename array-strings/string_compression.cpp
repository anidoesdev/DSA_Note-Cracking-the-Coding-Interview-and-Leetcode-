```python
def compression(s):
    mp = {}
    for ch in s:
        if ch in mp:
            mp[ch] += 1
        else:
            mp[ch] = 1
    res = ""
    for ch in sorted(mp.keys()):
        res += ch
        res += str(mp[ch])
    return res

str = "aabcccdd"
print(compression(str))
```