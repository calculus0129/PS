import java.util.Scanner;
public class b31090_2023_what_so_special {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int t = sc.nextInt(), n;
        while(t-->0) {
            n = sc.nextInt();
            System.out.println((n+1)%(n%100)==0?"Good":"Bye");
        }
    }
}
