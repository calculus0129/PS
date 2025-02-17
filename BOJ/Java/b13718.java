import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class b13718 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        try {
            _main(args);
        } catch (Exception e) {
            bw.write(Arrays.toString(e.getStackTrace()));
        }
        bw.close();
    }
    public static void _main(String[] args) throws IOException {
        int[] inp = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int n = inp[0], m = inp[1], k = inp[2], x = inp[3]-1;
        int[] mapIdx = new int[m];
        String s = br.readLine();
        List<Integer> charIdx = new ArrayList<>();
        for(int idx = s.indexOf('#');idx>=0;idx = s.indexOf('#', charIdx.get(charIdx.size()-1)+1)) {
            charIdx.add(idx);
        }
        assert(charIdx.size() == m);

        for(int i=m-1;i>=0;--i) {
            mapIdx[i] = x % k;
            x /= k;
        }

        char[] cs = s.toCharArray();
        for(int i=0;i<m;++i) {
            cs[charIdx.get(i)] = Arrays.stream(br.readLine().split("")).sorted().map(tmp -> tmp.charAt(0)).collect(Collectors.toList()).get(mapIdx[i]);
        }
        bw.write(String.valueOf(cs));
//        List<String> sortedInp = Arrays.stream(br.readLine().split("")).sorted().collect(Collectors.toList());
//        bw.write(sortedInp.toString());
    }
}
