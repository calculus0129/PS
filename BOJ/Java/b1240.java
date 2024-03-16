import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

class pair {
    int x;
    int dist;
    pair(int x, int dist) {
        this.x = x;
        this.dist = dist;
    }
}

public class b1240 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int m, n;

    static Map<Integer, List<pair>> graph = new HashMap<>();
    static Set<Integer> visited = new HashSet<>();

    private static void addoneEdge(int a, int b, int c) {
        if(!graph.containsKey(a)) graph.put(a, new ArrayList<>());
        graph.get(a).add(new pair(b, c));
    }
    private static void addEdge(int a, int b, int c) {
        addoneEdge(a, b, c);
        addoneEdge(b, a, c);
    }

    public static void main(String[] args) throws IOException {
        int[] input = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        m = input[1];
        n = input[0];
        for(int i=1;i<n;++i) {
            int[] newinput = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            addEdge(newinput[0], newinput[1], newinput[2]);
        }
        while(m-->0) {
            List<Integer> tmp = Arrays.stream(br.readLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
            visited.clear();
            bw.write(String.format("%d\n", dist(tmp.get(0), tmp.get(1))));
        }
        bw.close();
    }

    private static int dist(int from, int to) {
        if(from == to) return 0;
        int ret=-1;
        visited.add(from);
        for(pair p: graph.get(from)) {
            if(!visited.contains(p.x)) {
                ret = dist(p.x, to);
                if(ret>=0) {
                    ret += p.dist;
                    break;
                }
            }
        }
        return ret;
    }
}
