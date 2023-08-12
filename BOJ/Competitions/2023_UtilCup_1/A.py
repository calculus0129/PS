n = int(input())
arr = list(map(int, input().split()))
out = []
for i in arr:
        if i == 300:
                out.append(1)
        elif i >= 275:
                out.append(2)
        elif i>= 250:
                out.append(3)
        else: out.append(4)
for i in out:
        print(i, end = ' ')
