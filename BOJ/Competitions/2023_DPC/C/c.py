n = int(input())-1
s, tmp = '1', ''
while n>0:
        d = {}
        for i in s:
                if i not in d:
                        d[i]=1
                else:
                        d[i]+=1
        tmp=''
        for i in sorted(d):
                tmp+=i+str(d[i])
        s=tmp
        n-=1
print(s)
#s=int(s)
print(max(s))
