import java.io.*;

public class b1105 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int l, r;
    public static void main(String[] args) throws IOException {
        String input[] = br.readLine().split(" ");
        l = Integer.parseInt(input[0]);
        r = Integer.parseInt(input[1]);
        int num = l, tmp=last_8(num);
        while(num8(num)>0 && tmp<=r) {
            num = tmp;
            tmp = last_8(num);
        }
        bw.write(""+num8(num));
        bw.close();
    }
    private static int num8(int a) {
        int ret=0;
        while(a!=0) {
            if(a%10==8) ret++;
            a/=10;
        }
        return ret;
    }
    private static int last_8(int a) {
        int cnt=0;
        while(a!=0) {
            if(a%10==8) {
                a++;
                while(cnt-->0) a*=10;
                return a;
            }
            cnt++;
            a/=10;
        }
        return a; // 0
    }
}
