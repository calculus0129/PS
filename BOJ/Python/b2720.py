import sys

fast_i = sys.stdin.readline
fast_o = sys.stdout.write

t = int(input())
while t>0:
    t-=1
    c = int(fast_i().strip())
    q = c//25
    c %= 25
    d = c//10
    c %= 10
    n = c//5
    c %= 5
    p = c
    fast_o(f"{q} {d} {n} {p}\n")
