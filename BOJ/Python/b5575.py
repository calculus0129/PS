for _ in range(3):
    a = list(map(int, input().split()))
    t = (a[5]-a[2])+(a[4]-a[1])*60+(a[3]-a[0])*3600
    print(t//3600, (t//60)%60, t%60)