import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class b2231_divide_sum {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int ans = work(Integer.parseInt(br.readLine())); //정수 입력 받을 때
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(ans+"\n");
        bw.flush();
        bw.close();

    }
    public static int work(int n) {
        for(int i=1;i<=n;++i) if(n == split_sum(i)) {
            return i;
        }
        return 0;
    }

    public static int split_sum(int n) {
        int ret = n;
        while(n>0) {
            ret += n%10;
            n/=10;
        }
        return ret;
    }
}
