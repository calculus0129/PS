import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;

public class b2522 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine()), i=1, j;
        for(;i<=n;++i) {
            for(j=0;j<n-i;++j) bw.write(" ");
            for(j=0;j<i;++j) bw.write("*");
            bw.write("\n");
        }
        for(i-=2;i>0;--i) {
            for(j=0;j<n-i;++j) bw.write(" ");
            for(j=0;j<i;++j) bw.write("*");
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}
