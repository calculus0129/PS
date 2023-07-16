a, b = map(int, input().split())
if a<b or a+b&1==1:
        print(-1)
else:
        print(a+b>>1, a-b>>1)
