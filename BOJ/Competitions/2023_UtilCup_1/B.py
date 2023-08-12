class date:
        def __init__(self, yr: int, mt: int, dt: int):
                self.y = yr
                self.m = mt
                self.d = dt
        def __le__(self, o) -> bool:
                if self.y<o.y: return True
                elif self.y==o.y:
                        if self.m<o.m: return True
                        elif self.m == o.m:
                                if self.d <= o.d: return True
                return False

if __name__ == "__main__":
        a, b, c = map(int, input().split('-'))
        d = date(a, b, c)
        n = int(input())
        cnt = 0
        while n:
                n-=1
                a, b, c = map(int, input().split('-'))
                cnt += 1 if d <= date(a, b, c) else 0
        print(cnt)
