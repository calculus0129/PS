import java.io.BufferedWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;

public class b1100 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        int j, ans=0;
        for(int i=0;i<8;++i) {
            String s = br.readLine();
            for(j=0;j<8;++j) if(((i+j^1)&1) == 1 && s.charAt(j) == 'F') ans++;
        }
        bw.write(""+ans);
        bw.flush();
        bw.close();
    }
}
