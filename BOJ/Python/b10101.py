A = []
A.append(int(input()))
A.append(int(input()))
A.append(int(input()))

A.sort()
if A[0] == 60 and A[2] == 60:
        print("Equilateral")
elif A[0] + A[1] + A[2] != 180:
        print("Error")
elif A[0] == A[1] or A[1] == A[2]:
        print("Isosceles")
else:
        print("Scalene")
