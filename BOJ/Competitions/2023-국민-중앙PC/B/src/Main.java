import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int n = Integer.parseInt(sc.nextLine());
        List<Integer> s = Arrays.stream(sc.nextLine().split(" ")).map(i -> Integer.parseInt(i)).collect(Collectors.toList());
        int streak=0, cstreak=0;
        for(int i: s) {
            if(i == 0) {
                streak = (streak < cstreak)?cstreak:streak;
                cstreak = 0;
            }
            else cstreak++;
            //System.out.println("streak: "+streak+" cstreak: "+cstreak);
        }
        System.out.printf("%d", (streak < cstreak)?cstreak:streak);
    }
}
