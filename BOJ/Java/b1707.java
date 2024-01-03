import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.List;

public class b1707 {
    static int v;
    static List<Integer>[] lists = new List[20001];
    static boolean[] color = new boolean[20001];
    static boolean[] visited = new boolean[20001];
    static boolean[] discovered = new boolean[20001];
    public static void main(String[] args) throws IOException {
        for(int i=1;i<=20000;++i) {
            List<Integer> l = new ArrayList<>();
            lists[i] = l;
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t--!=0) {
            String[] s = br.readLine().split(" ");
            v = Integer.parseInt(s[0]);
            for(int i=v;i>0;--i) lists[i].clear();
            int e = Integer.parseInt(s[1]);
            while(e--!=0) {
                s = br.readLine().split(" ");
                int a = Integer.parseInt(s[0]), b = Integer.parseInt(s[1]);
                lists[a].add(b);
                lists[b].add(a);
            }
            System.out.println(right()?"YES":"NO");
        }
    }
    private static boolean right() {
        color = new boolean[20001];
        visited = new boolean[20001];
        discovered = new boolean[20001];
        for(int i=1;i<=v;++i) if(!visited[i]) {
            discovered[i] = true;
            if(!dfs(i)) return false;
        }
        return true;
    }
    private static boolean dfs(int node) {
        for(int nxt: lists[node]) {
            if(discovered[nxt] && color[nxt] == color[node]) return false;
            discovered[nxt] = true;
            color[nxt] = !color[node];
        }
        visited[node] = true;
        for(int nxt: lists[node]) if(!visited[nxt] && !dfs(nxt)) return false;
        return true;
    }
}
