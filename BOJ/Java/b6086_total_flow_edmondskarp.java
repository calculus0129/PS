import java.io.*;
import java.util.*;

public class b6086_total_flow_edmondskarp {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static Map<Character, Set<Character>> adj = new HashMap<>();
    static int[][] cap = new int[52][52], flow = new int[52][52];
    static boolean[] labeled = new boolean[52], scanned = new boolean[52];

    private static int charidx(char c) {
        return (int)c<(int)'a'?(int)c-(int)'A':(int)c-(int)'a'+26;
    }
    static Queue<Character> que = new LinkedList<>();
    static Map<Character, Character> prev = new HashMap<>();

    public static void main(String[] args) throws IOException {
        try {
            int n = Integer.parseInt(br.readLine());
            for(int _i=0;_i<n;++_i) {
                String[] input = br.readLine().split(" ");
                char u = input[0].charAt(0), v = input[1].charAt(0);
                int w = Integer.parseInt(input[2]);
                cap[charidx(u)][charidx(v)] = cap[charidx(v)][charidx(u)] = cap[charidx(u)][charidx(v)]+w;
                adj.putIfAbsent(u, new TreeSet<>());
                adj.putIfAbsent(v, new TreeSet<>());
                adj.get(u).add(v);
                adj.get(v).add(u);
            }

            int value=0, v;
            while(labelandscan()) {
                value += augmentflow();
            }
            bw.write(Integer.toString(value));
            bw.close();
        } catch (Exception e) {
            bw.close();
            e.printStackTrace();
        }
    }
    private static boolean labelandscan() throws IOException {
        for(int i=0;i<52;++i) labeled[i] = scanned[i] = false;
        que.clear();
        prev.clear();
        que.add('A');
        labeled[charidx('A')]=true;
        while(!que.isEmpty() && !prev.containsKey('Z')) {
            scan(que.poll());
        }
        return prev.containsKey('Z');
    }
    private static void scan(char node) throws IOException {
//        bw.write("scan: "+node+'\n');
//        bw.flush();
        scanned[charidx(node)] = true;
        for(char v: adj.get(node)) if(cap[charidx(node)][charidx(v)]-flow[charidx(node)][charidx(v)]>0 && !scanned[charidx(v)]) {
            que.add(v);
            prev.put(v, node);
        }
    }
    private static int augmentflow() {
        int f = Integer.MAX_VALUE;
        for(char c = 'Z';c!='A';c=prev.get(c)) {
            f = Math.min(f, cap[charidx(prev.get(c))][charidx(c)]-flow[charidx(prev.get(c))][charidx(c)]);
        }
        for(char c = 'Z';c!='A';c=prev.get(c)) {
            flow[charidx(prev.get(c))][charidx(c)] += f;
            flow[charidx(c)][charidx(prev.get(c))] -= f;
        }
        return f;
    }
}
