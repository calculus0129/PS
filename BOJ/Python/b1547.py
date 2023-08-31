target = 1
n = int(input())

for _ in range(n):
        a, b = map(int, input().split())
        if a == target:
                target = b
        elif b == target:
                target = a
print(target)
