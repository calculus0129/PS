a, b = input().split()
ans=len(a)
for i in range(len(b)-len(a)+1):
    cnt=0
    for j in range(len(a)):
        if b[i+j] != a[j]: cnt+=1
    if cnt < ans: ans=cnt
print(ans)
