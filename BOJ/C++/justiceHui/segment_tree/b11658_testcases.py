import random as r


m, n, Arr = 0, 0, []
OUT, ANS="", ""

def inp():
        global n, Arr, OUT
        n, Arr = int(input('n: ')), []
        for i in range(n): Arr.append(list(map(int, input(f'Arr [{i+1}]: ').split())))
        OUT += f'{n}\n'
        for i in Arr:
                for j in i:
                        OUT += f'{j} '
                OUT += '\n'
        

def s(x1, y1, x2, y2):
        global Arr, m, ANS, OUT
        ret = 0
        for i in range(x1-1, x2):
                for j in range(y1-1, y2):
                        ret += Arr[i][j]
        m+=1
        OUT += f"1 {x1} {y1} {x2} {y2}\n"
        ANS += f'{ret}\n'
        return ret

def ch(x, y, c):
        global m, Arr, OUT
        Arr[x-1][y-1]=c
        OUT += f"0 {x} {y} {c}\n"
        m+=1

def T1():
        global n, OUT, ANS
        A = range(1, 1+n)
        for i1 in A:
                for i2 in A:
                        if i2>=i1:
                                for j1 in A:
                                        for j2 in A:
                                                if j2 >= j1:
                                                        s(i1, j1, i2, j2)

def T2():
        global n, OUT, ANS
        for i in range(n):
                for j in range(n):
                        ch(i+1, j+1, r.randint(1, 100000))
        A = range(1, 1+n)
        for i1 in A:
                for i2 in A:
                        if i2>=i1:
                                for j1 in A:
                                        for j2 in A:
                                                if j2 >= j1:
                                                        s(i1, j1, i2, j2)

def final():
        global OUT, ANS, m
        OUT = OUT[0] + ' ' + str(m) + OUT[1:]
        print(OUT)
        print('\nAnswer\n')
        print(ANS)

if __name__=="__main__":
        inp()
        T1()
        T2()
        final()
