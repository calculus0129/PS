import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;

import static java.lang.Integer.min;

public class b1229 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int yookgaksu[] = new int[1000001];
    public static void main(String[] args) throws IOException {
        init();
        int n = Integer.parseInt(br.readLine());
        bw.write(""+yookgaksu[n]);
        bw.flush();
        bw.close();
    }
    private static int yookgak(int i) {
        return (i-1)*(i*3-(i-1)) + 1;
    }
    private static void init() {
        int r;
        for(int i=1;;++i) {
            r = yookgak(i);
            if(r>1000000) break;
            yookgaksu[r] = 1;
        }
        for(int i=2;i<=5;++i) {
            yookgaksu[i] = i;
        }
        for(int i=7;i<=11;++i) {
            yookgaksu[i] = i-5;
        }
        yookgaksu[12] = 2;
        yookgaksu[26] = 6;
        r = 2;
        for(int i=13, j;i<=1000000;++i) if(yookgaksu[i]==0) {
            if(yookgak(r+1)<i) r++;
            yookgaksu[i] = yookgaksu[i-1] + 1;
            for(j=2;j<=r;++j) {
                yookgaksu[i] = min(yookgaksu[i], yookgaksu[i-yookgak(j)] + 1);
            }
        }
    }
}
