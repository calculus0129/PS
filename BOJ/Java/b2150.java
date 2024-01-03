import java.io.*;

public class b2150 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        int v, e;
        String[] input = br.readLine().split(" ");
//        bw.write(""+input.length); // 2
        v = Integer.parseInt(input[0]);
        e = Integer.parseInt(input[1]);
        bw.write(""+v+" "+e);
        bw.flush();
        bw.close();
    }
}
