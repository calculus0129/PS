import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.lang.Math;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] cs1 = ('\0' + br.readLine()).toCharArray(), cs2 = ('\0' + br.readLine()).toCharArray();
        int[][] dp = new int[cs1.length][cs2.length];
        for(int i=1, ie=cs1.length, j, je=cs2.length;i<ie;++i) {
            for(j=1;j<je;++j) {
                if(cs1[i] == cs2[j]) dp[i][j] = dp[i-1][j-1]+1;
                dp[i][j] = Math.max(dp[i][j], Math.max(dp[i-1][j], dp[i][j-1]));
            }
        }

        System.out.println(dp[cs1.length-1][cs2.length-1]);

        String ans = "";

        for(int i=cs1.length-1, j=cs2.length-1; i>0 && j>0; ) {
            if(dp[i][j] == dp[i-1][j]) --i;
            else if(dp[i][j] == dp[i][j-1]) --j;
            else {
                ans = cs1[i] + ans;
                --i; --j;
            }
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(ans);
        bw.flush();
        bw.close();

    }
}
