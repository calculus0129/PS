import java.util.Scanner;

public class b1049 {
    static int m, n;
    static int[] arr = new int[3];
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        input();
        System.out.println(work());
    }
    public static void input() {
        arr[0] = arr[1] = 1010;
        String s[] = sc.nextLine().trim().split(" ");
        m = Integer.parseInt(s[0]);
        n = Integer.parseInt(s[1]);
        while(n-- > 0) {
            s = sc.nextLine().trim().split(" ");
            arr[0] = Math.min(arr[0], Integer.parseInt(s[0]));
            arr[1] = Math.min(arr[1], Integer.parseInt(s[1]));
        }
        assert (n==-1);
    }
    public static int work() {
        int a = Math.min(arr[0], arr[1]*6), b = Math.min(arr[0], arr[1]*(m%6));
        return (m/6)*a+b;
    }
}
