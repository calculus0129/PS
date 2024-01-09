import java.io.*;
import java.util.Arrays;

// 반올림 https://cordcat.tistory.com/70

public class b5787 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int l, i;
        l = Integer.parseInt(br.readLine());
        while(l!=0) {
            int[][] std = new int[l][l], scanned = new int[l][l];
            for(i=0;i<l;++i) {
                String tmp = br.readLine();
                std[i] = Arrays.stream(tmp.split(" ")).mapToInt(x->Integer.parseInt(x)).toArray();
            }
            for(i=0;i<l;++i) {
                String tmp = br.readLine();
                scanned[i] = Arrays.stream(tmp.split(" ")).mapToInt(x->Integer.parseInt(x)).toArray();
            }
            int acc = accuracy(std, scanned, l);
            bw.write(String.format("%.2f\n", 100*(double)acc/(l*l)));

            l = Integer.parseInt(br.readLine());
        }
        bw.close();
    }

    private static int accuracy(final int[][] std, final int[][] sc, int l) {
        int i, j, s;
        int[] tmp=new int[8];
        for(i=0;i<l;++i) for(j=0;j<l;++j) {
            s = std[i][j];
            tmp[0] += proximate(s, sc[i][j]);
            tmp[1] += proximate(s, sc[j][l-1-i]);
            tmp[2] += proximate(s, sc[l-1-i][l-1-j]);
            tmp[3] += proximate(s, sc[l-1-j][i]);

            tmp[4] += proximate(s, sc[j][i]);
            tmp[5] += proximate(s, sc[i][l-1-j]);
            tmp[6] += proximate(s, sc[l-1-j][l-1-i]);
            tmp[7] += proximate(s, sc[l-1-i][j]);
        }
        return Math.max(
                Math.max(Math.max(tmp[0], tmp[1]), Math.max(tmp[2], tmp[3])),
                Math.max(Math.max(tmp[4], tmp[5]), Math.max(tmp[6], tmp[7]))
        );
    }

    private static int proximate(int a, int b) {
        return Math.abs(a-b)<=100?1:0;
    }

}
