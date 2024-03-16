import java.util.Scanner;
public class b2455 {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int ans = 0;
        for(int i=0, a, b, cur=0;i<4;++i) {
            a = sc.nextInt();
            b = sc.nextInt();
            cur += b - a;
            if(ans<cur) ans = cur;
        }
        System.out.println(ans);
    }
}
