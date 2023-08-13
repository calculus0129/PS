def fizb(i):
        if i%3==0:
                if i%5==0:
                        print("FizzBuzz")
                else:
                        print("Fizz")
        elif i%5 == 0:
                print("Buzz")
        else:
                print(i)

a=[]
a.append(input())
a.append(input())
a.append(input())
for i in range(3):
        try:
                int(a[i])
        except ValueError:
                pass
        else:
                break
fizb(int(a[i])+3-i)
