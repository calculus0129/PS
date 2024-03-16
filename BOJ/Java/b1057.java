import java.util.Scanner;
public class b1057 {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        sc.nextInt();
        int a = sc.nextInt()-1, b = sc.nextInt()-1;
        int ans = 0;
        while(a!=b) {
            ++ans;
            a>>=1;
            b>>=1;
        }
        System.out.println(ans);
    }
}
