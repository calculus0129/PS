import sys

fast_input = sys.stdin.readline
fast_write = sys.stdout.write

s = fast_input().strip()
ans, cnt = 0, 0
for i in range(len(s)):
    if s[i] == '(':
        cnt += 1
    elif s[i-1] == '(':
        cnt -= 1
        ans += cnt
    else:
        cnt -= 1
        ans += 1
fast_write(ans.__repr__())
