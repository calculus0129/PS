import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;
public class b1124_tle {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int a = sc.nextInt(), b = sc.nextInt();
        int ans=0;
        for(int i=a;i<=b;++i) if(is_underprime(i)) ++ans;
        System.out.print(ans);
    }
    private static boolean is_underprime(int n) {
        return is_prime(pf(n).size());
    }
    private static List<Integer> pf(int n) {
        List<Integer> ret = new ArrayList<>();
        int p=3;
        while((n&1)==0) {
            ret.add(2);
            n>>=1;
        }
        while(n!=1) {
            if(is_prime(p)) {
                while(n%p==0) {
                    n/=p;
                    ret.add(p);
                }
            }
            p+=2;
        }
        return ret;
    }
    private static boolean is_prime(int p) {
        if((p&1)==0) return p==2;
        if(p==1) return false;
        for(int i=3;i*i<=p;i+=2) if(p%i==0) return false;
        return true;
    }
}
