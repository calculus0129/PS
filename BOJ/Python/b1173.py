# import sys

# fast_i = sys.stdin.readline
# fast_w = sys.stdout.write
N, m, M, T, R = map(int, input().split())
if m+T>M: print(-1)
else:
    X = m
    cnt, t = 0, 0
    while cnt<N:
        if X+T<=M:
            cnt += 1
            X += T
        else:
            X = max(m, X-R)
        t+=1
    print(t)