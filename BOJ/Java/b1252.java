import java.io.IOException;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static boolean[] v1 = new boolean[81], v2 = new boolean[81];
    public static void main(String[] args) throws IOException {
        boolean[] res = new boolean[81], olim = new boolean[81];
        String[] s = br.readLine().split(" ");
        String s1 = s[0], s2 = s[1];
        int l=-1;
        for(int e=s1.length()-1, i=e;i>=0;--i) v1[i] = s1.charAt(e-i) == '1';
        for(int e=s2.length()-1, i=e;i>=0;--i) v2[i] = s2.charAt(e-i) == '1';
        for(int i=0, val;i<80;++i) {
            val = (v1[i]?1:0) + (v2[i]?1:0) + (olim[i]?1:0);
            if(val==0) continue;
            if((res[i] = (val & 1) == 1)) l=i;
            olim[i+1] = (val&2) == 2;
        }
        if(res[80] = olim[80]) l=80;
        if(l==-1) {
            bw.write("0");
        } else {
            for(int i=l;i>=0;--i) bw.write(res[i]?"1":"0");
        }
        bw.flush();
        bw.close();
    }
}
