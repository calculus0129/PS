import sys

fast_input = sys.stdin.readline
fast_write = sys.stdout.write

n, m = map(int, fast_input().split())

arr = [''] * (n+1)
inv_arr = {}
for i in range(1, n+1):
    s = fast_input().strip()
    arr[i] = s
    inv_arr[s] = i
for _ in range(m):
    s=fast_input().strip()
    if s.isdigit():
        fast_write(f"{arr[int(s)]}\n")
    else:
        fast_write(f"{inv_arr[s]}\n")

"""
import sys

input = sys.stdin.readline

n,m = map(int,input().split())

dt = {}
li = [""] * (n + 1)

for i in range(1,n+1):
    name = input().strip()
    dt[name] = i
    li[i] = name

for r in range(1,m+1):
    problem = input().strip()
    if problem.isdigit():
        print(li[int(problem)])
    else:
        print(dt[problem])
"""



"""
n,m = map(int,input().split())

dt = {}
li = []

for i in range(1,n+1):
    name = input()
    dt[name] = i
    li.append(name)



for r in range(1,m+1):
    problem = input()
    if problem.isdigit():
        print(li[int(problem)-1])
    else:
        print(dt[problem])
"""

"""
import sys

n, m = map(int, sys.stdin.readline().split())
pok = {}
num = {}
for i in range(1, n + 1):
    name = sys.stdin.readline().strip()  
    pok[name] = i
    num[i] = name

for _ in range(m):
    q = sys.stdin.readline().strip()  
    if q.isdigit():
        print(num[int(q)])
    else:
        print(pok[q])
"""