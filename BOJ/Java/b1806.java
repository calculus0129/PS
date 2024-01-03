/**
 * Created by ryanb on 2023-08-25.
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class b1806 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]), sum = Integer.parseInt(s[1]);
        int[] arr = new int[n+1];
        s = br.readLine().split(" ");
        for(int i=1;i<=n;++i) arr[i] = Integer.parseInt(s[i-1]) + arr[i-1];
        int i=0, j=1, ans=0;
        while(i<n) {
            if(arr[j]-arr[i] >= sum) {
                if(ans == 0 || j-i<ans) ans = j-i;
                if(i<j) ++i;
                else ++j;
            }
            else if(j==n) {
                ++i;
            }
            else {
                ++j;
            }
        }
        System.out.print(ans);
    }
}
