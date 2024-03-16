import java.util.Scanner;
public class b1392 {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt(), q = sc.nextInt();
        int[] t = new int[n*100];
        for(int i=1, a, c=0, j;i<=n;++i) {
            a = sc.nextInt();
            for(j=0;j<a;++j) t[c+j] = i;
            c += a;
        }
        while(q-->0) {
            System.out.println(t[sc.nextInt()]);
        }
    }
}
