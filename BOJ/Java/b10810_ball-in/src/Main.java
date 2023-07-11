import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        int[] arr = new int[n+1];
        while(m--!=0) {
            int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();
            for(int i=a;i<=b;++i) {
                arr[i] = c;
            }
        }
        for(int i=1;i<=n;++i) {
            System.out.print(arr[i]);
            System.out.print(' ');
        }
    }
}