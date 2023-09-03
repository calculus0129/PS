import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        long n = sc.nextLong(); // java: 64bit integer is represented by long.
        System.out.println(n*(n+1)*(n-1)/2L);
    }
}
