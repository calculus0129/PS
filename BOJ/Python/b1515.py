# https://velog.io/@cria2000/백준-1515-수-이어-쓰기python
import sys
inp = sys.stdin.readline
wr = sys.stdout.write
# print(inp().rstrip())

nums = inp().rstrip()
ans, idx, n, out = 0, 0, len(nums), False

while not out and idx<n:
    ans+=1
    for c in str(ans):
        if idx>=n:
            out=True
            break
        if c == nums[idx]:
            idx+=1
wr(str(ans))
