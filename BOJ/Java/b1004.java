import java.io.*;
public class b1004 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        int a, b, c, d, n, x, y, r, ans;
        while(t-->0) {
            ans=0;
            {
                String[] input = br.readLine().split(" ");
                a = Integer.parseInt(input[0]);
                b = Integer.parseInt(input[1]);
                c = Integer.parseInt(input[2]);
                d = Integer.parseInt(input[3]);
            }
            n = Integer.parseInt(br.readLine());
            while(n-->0) {
                String[] input = br.readLine().split(" ");
                x = Integer.parseInt(input[0]);
                y = Integer.parseInt(input[1]);
                r = Integer.parseInt(input[2]);
                if(sqr(x-a)+sqr(y-b)<sqr(r) ^ sqr(c-x)+sqr(d-y)<sqr(r)) ++ans;
            }
            System.out.println(ans);
        }
    }
    private static int sqr(int x) {
        return x*x;
    }
}
