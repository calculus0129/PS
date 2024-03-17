import sys

readline = sys.stdin.readline

for _ in range(3):
    a = int(readline().strip())
    s = 0
    for __ in range(a):
        s += int(readline().strip())
    print(0 if s==0 else ('+' if s>0 else '-'))
