import java.io.*;
import java.util.Arrays;
import java.util.Set;
import java.util.TreeSet;
import java.util.stream.Collectors;

public class b10815 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        int m = Integer.parseInt(br.readLine());
        Set<Integer> s = Arrays.stream(br.readLine().split(" ")).map(Integer::parseInt).collect(Collectors.toCollection(TreeSet::new));
        int n = Integer.parseInt(br.readLine());
        for(int i: Arrays.stream(br.readLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList())) {
            bw.write(s.contains(i)?"1 ":"0 ");
        }
        bw.close();
    }
}
