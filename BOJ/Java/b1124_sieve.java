import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;
public class b1124_sieve {
    static Set<Integer> primes = new TreeSet<>();
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        init_prime();
        int a = sc.nextInt(), b = sc.nextInt();
        int ans = 0;
        for(int i=a;i<=b;++i) if(is_underprime(i)) ans++;
        System.out.print(ans);
    }
    private static void init_prime() {
        primes.add(2);
        boolean r;
        for(int i=3;i<100000;++i) {
            r=true;
            for(int p: primes) if(i%p==0) {
                r = false;
                break;
            }
            if(r) primes.add(i);
        }
    }
    private static boolean is_prime(int p) {
        return primes.contains(p);
    }
    private static int pf_num(int n) {
        int ret = 0;
        for(int p: primes) {
            while(n%p==0) {
                ret++;
                n/=p;
            }
            if(n==1) break;
        }
        return ret;
    }
    private static boolean is_underprime(int n) {
        return is_prime(pf_num(n));
    }
}
