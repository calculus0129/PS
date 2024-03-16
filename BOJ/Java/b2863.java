import java.io.*;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class b2863 {
    static double biggest = 0.0f;
    static int ans = 0;
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static void work(int a, int b, int d, int c, int num) {
        double tmp = (double) a / c + (double) b / d;
        if(tmp>biggest) {
            ans = num;
            biggest = tmp;
        }
    }
    public static void main(String[] args) throws IOException {
        int a, b, c, d;
        List<Integer> tmp = Arrays.stream(br.readLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList()), tmp2 = Arrays.stream(br.readLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
        a = tmp.get(0);
        b = tmp.get(1);
        c = tmp2.get(0);
        d = tmp2.get(1);
        work(a, b, d, c, 0);
        work(c, a, b, d, 1);
        work(d, c, a, b, 2);
        work(b, d, c, a, 3);
        bw.write(""+ans);
        bw.close();
    }
}
