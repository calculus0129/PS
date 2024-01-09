import java.util.Scanner;

public class b4696_StIves {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double n = sc.nextDouble();
        while(n!=0) {
            System.out.printf("%.2f\n", 1 + n + n*n + n*n*n + n*n*n*n);
            n = sc.nextDouble();
        }
    }
}
