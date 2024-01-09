// https://blog.naver.com/ki_dongg/223134121519
import java.util.Arrays;
import java.util.Scanner;

public class b1303_war_battle {
    public static int m, n, cnt;
    public static int ans[] = new int[2];
    public static Scanner sc = new Scanner(System.in);
    public static int[][] g, dir = {{0,-1}, {1,0}, {0,1}, {-1,0}};
    public static boolean[][] visited = new boolean[101][101];
    public static void input() {
        n = sc.nextInt();
        m = sc.nextInt();
        g = new int[m][n];
        String s;
        char c;
        for(int i=0, j;i<m;++i) {
            s = sc.next();
            for(j=0;j<n;++j) g[i][j] = (s.charAt(j)=='W')?0:1;
        }
    }
    public static void main(String[] args) {
        input();
        //debug();
        for(int i=0,j;i<m;++i) for(j=0;j<n;++j) if(!visited[i][j]) {
            visit(i, j);
            ans[g[i][j]]+=cnt*cnt;
            cnt = 0;
        }
        output();
    }
    public static void visit(int x, int y) {
        visited[x][y]=true;
        ++cnt;
        for(int[] i: dir) {
            int nx = x + i[0], ny = y + i[1];
            if(nx<0 || ny<0 || nx>=m || ny>=n || g[nx][ny]!=g[x][y] || visited[nx][ny]) continue;
            //if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
            //if (g[nx][ny]!=g[x][y] || visited[nx][ny]) continue;
            visit(nx, ny);
        }
    }
    public static void output() {
        System.out.print(ans[0]+" "+ans[1]);
    }
    public static void debug() {
        for(int i=0, j;i<m;++i) System.out.println(Arrays.toString(g[i]));
    }
}
