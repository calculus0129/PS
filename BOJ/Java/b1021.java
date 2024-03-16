import java.util.Scanner;
import java.util.LinkedList;
import java.util.Deque;
public class b1021 {
    static Scanner sc = new Scanner(System.in);
    static Deque<Integer> deq = new LinkedList<>();
    public static void main(String[] args) {
        int n = sc.nextInt(), m = sc.nextInt(), x, ans=0;
        for(int i=1;i<=n;++i) deq.add(i);
        while(m-->0) {
            x = find(sc.nextInt());
            if(x>=0) {
                ans += x;
                while(x-->0) deq.add(deq.remove());
                deq.remove();
            }
            else {
                ans -= x;
                while(x++<0) deq.addFirst(deq.removeLast());
                deq.remove();
            }
        }
        System.out.println(ans);
    }
    private static int find(int x) {
        Deque<Integer> tmp = new LinkedList<>(deq);
        int a, b, cnt=0;
        if(tmp.remove() == x) return 0;
        do {
            a = tmp.remove();
            b = tmp.isEmpty()?0:tmp.pollLast();
            ++cnt;
        } while(a!=x && b!=x);
        if(a==x) return cnt;
        else return -cnt;
    }
}
