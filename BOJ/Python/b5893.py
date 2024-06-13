import sys, os
inp = sys.stdin.readline
out = sys.stdout.write

a = int(inp()[:-1], 2)
print(bin(17*a)[2:])
