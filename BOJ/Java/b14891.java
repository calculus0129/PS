import java.util.Scanner;
import java.util.LinkedList;
import java.util.stream.Collectors;

public class b14891 {
    static Scanner sc = new Scanner(System.in);

    private class chain {
        LinkedList<Boolean> l1; // cw from 9 o'clock
        LinkedList<Boolean> l2; // cw from 3 o'clock
        public chain() {
            l1 = new LinkedList<>();
            l2 = new LinkedList<>();
        }
        public chain(LinkedList<Character> num) {
            num.addFirst(num.removeLast());
            num.addFirst(num.removeLast());
            l1 = new LinkedList<>();
            l2 = new LinkedList<>();
            int cnt = 0;
            for(Character i: num) {
                if(cnt++<4) {
                    l1.add(i!='0');
                } else {
                    l2.add(i!='0');
                }
            }
        }
        public void cw() {
            l2.addFirst(l1.removeLast());
            l1.addFirst(l2.removeLast());
        }
        public void ccw() {
            l2.addLast(l1.removeFirst());
            l1.addLast(l2.remove());
        }
        public int c12() {
            return l1.get(2)?1:0;
        }
        public boolean c3() {
            return l2.getFirst();
        }
        public boolean c9() {
            return l1.getFirst();
        }
    }
    private static boolean matches(chain c1, chain c2) {
        return c1.c3() != c2.c9();
    }

    static chain[] wee = new chain[4];


    public static void main(String[] args) {
        b14891 test = new b14891();
        test._main();
        int n = sc.nextInt();
        while(n-->0) {
            int i = sc.nextInt()-1, dir = sc.nextInt();
            right(i, dir==1);
            if(dir==1) wee[i].ccw();
            else wee[i].cw();
            left(i, dir==1);
        }
        int score = 0;
        for(int i=3;i>=0;--i) {
            score<<=1;
            score|=wee[i].c12();
        }
        System.out.print(score);
    }
    private static void right(int idx, boolean dir) {
        if(idx>=4) return;
        if(idx==3 || matches(wee[idx], wee[idx+1])) {
            right(idx+1, !dir);
        }
        if(dir) {
            wee[idx].cw();
        } else {
            wee[idx].ccw();
        }
    }

    private static void left(int idx, boolean dir) {
        if(idx<0) return;
        if(idx == 0 || matches(wee[idx-1], wee[idx])) {
            left(idx-1, !dir);
        }
        if(dir) {
            wee[idx].cw();
        } else {
            wee[idx].ccw();
        }
    }

    // https://almost-native.tistory.com/255
    public void _main() {
        for(int i=0;i<4;++i) wee[i] = new chain(sc.next().chars()
                .mapToObj(c -> (char) c)
                .collect(Collectors.toCollection(LinkedList::new)));
    }
}
