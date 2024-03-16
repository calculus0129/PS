import java.io.*;
import java.util.Arrays;

public class b2566 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        int i=1, j, x=1, y=1, a=0;
        int[] arr = new int[10];
        String s;
        for(;i<10;++i) {
            arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            for(j=0;j<9;++j) if(a<arr[j]) {
                a = arr[j];
                x = i;
                y = j+1;
            }
        }
        bw.write(String.format("%d\n%d %d", a, x, y));
        bw.close();
    }
}
