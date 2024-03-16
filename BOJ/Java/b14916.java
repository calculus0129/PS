import java.util.Scanner;
public class b14916 {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt(), cnt = 0;
        int ans = -1;
        while(n>=0) {
            if((n&1) == 0) ans = cnt+(n>>1);
            n-=5;
            ++cnt;
        }
        System.out.println(ans);
    }
}
