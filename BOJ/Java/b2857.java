import java.util.Scanner;
public class b2857 {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        boolean away = true;
        for(int i=1;i<=5;++i) {
            if(sc.next().contains("FBI")) {
                away = false;
                System.out.println(i);
            }
        }
        if(away) {
            System.out.println("HE GOT AWAY!");
        }
    }
}
