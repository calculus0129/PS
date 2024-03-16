import java.util.Scanner;
public class b5532 {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int l = sc.nextInt(), a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt(), d = sc.nextInt();
        System.out.println(l-Math.max((a+c-1)/c, (b+d-1)/d));
    }
}
