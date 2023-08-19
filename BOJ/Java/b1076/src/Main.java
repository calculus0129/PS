import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        String s1 = sc.next(), s2 = sc.next(), s3 = sc.next();
        int a = 0;
        switch (s1) {
            case "black":
                a = 0;
                break;
            case "brown":
                a = 1;
                break;
            case "red":
                a = 2;
                break;
            case "orange":
                a = 3;
                break;
            case "yellow":
                a = 4;
                break;
            case "green":
                a = 5;
                break;
            case "blue":
                a = 6;
                break;
            case "violet":
                a = 7;
                break;
            case "grey":
                a = 8;
                break;
            case "white":
                a = 9;
                break;
        }
        a *= 10;
        switch (s2) {
            case "black":
                a += 0;
                break;
            case "brown":
                a += 1;
                break;
            case "red":
                a += 2;
                break;
            case "orange":
                a += 3;
                break;
            case "yellow":
                a += 4;
                break;
            case "green":
                a += 5;
                break;
            case "blue":
                a += 6;
                break;
            case "violet":
                a += 7;
                break;
            case "grey":
                a += 8;
                break;
            case "white":
                a += 9;
                break;
        }
        int b = a;
        switch (s3) {
            case "black":
                a = 0;
                break;
            case "brown":
                a = 1;
                break;
            case "red":
                a = 2;
                break;
            case "orange":
                a = 3;
                break;
            case "yellow":
                a = 4;
                break;
            case "green":
                a = 5;
                break;
            case "blue":
                a = 6;
                break;
            case "violet":
                a = 7;
                break;
            case "grey":
                a = 8;
                break;
            case "white":
                a = 9;
                break;
        }
        System.out.print(b);
        while(a-->0) System.out.print("0");
    }
}
