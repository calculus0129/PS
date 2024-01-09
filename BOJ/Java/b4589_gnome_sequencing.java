import java.util.Scanner;
public class b4589_gnome_sequencing {
    public static void main(String[] args) {
        System.out.println("Gnomes:");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while(--n>=0) {
            work(sc);
        }
    }
    static void work(Scanner sc) {
        int x1 = sc.nextInt();
        int x2 = sc.nextInt();
        int x3 = sc.nextInt();
        if(x1<x2 && x2<x3 || x1>x2 && x2>x3) {
            System.out.println("Ordered");
        } else {
            System.out.println("Unordered");
        }
    }
}