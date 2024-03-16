import java.util.Scanner;
public class b2563 {
    static boolean[][] arr = new boolean[100][100];
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int n = sc.nextInt();
        for(int i=0, a, b, j, k;i<n;++i) {
            a = sc.nextInt();
            b = sc.nextInt();
            for (j = 0; j < 10; ++j) for (k = 0; k < 10; ++k) arr[a + j][b + k] = true;
        }
        int cnt = 0;
        for(int i=0, j;i<100;++i) for(j=0;j<100;++j) if(arr[i][j]) ++cnt;
        System.out.println(cnt);
    }
}
