import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class b1076 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        String s1 = br.readLine(), s2 = br.readLine(), s3 = br.readLine();
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
        String s = String.format("%d", b);
        bw.write(s);
        while(b!=0 && a-->0) bw.write("0");
        bw.flush();
        bw.close();
    }
}
