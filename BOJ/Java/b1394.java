import java.io.*;
import java.util.HashMap;
import java.util.Map;

// https://j3sung.tistory.com/1109
public class b1394 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        char[] letters = br.readLine().toCharArray(), pw = br.readLine().toCharArray(); // No need to trim().
        Map<Character, Integer> inv_map = new HashMap<>();
        int ans = 0, l = letters.length, i, n = pw.length, m = 1;

        for(i=l-1;i>=0;--i) inv_map.put(letters[i], i+1);
        for(i=0;i<n;++i) {
            ans = (ans + inv_map.get(pw[n-1-i])*m) % 900528;
            m = (m*l) % 900528;
        }

        bw.write(Integer.toString(ans));
        bw.close();
    }
}
