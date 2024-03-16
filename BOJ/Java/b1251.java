import java.util.Scanner;
public class b1251 {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        String s = sc.next(), ans = "";
        int idx=0, n=s.length(), step=0;
        String m, tmp;
        while(step++<2 && idx<n) {
            s = s.substring(idx);
            n = s.length();
            m = s.substring(0, idx=1);
            for(int i=2;i<=n-(3-step);++i) {
                if(m.compareTo(tmp=rev(s.substring(0, i)))>0) {
                    idx = i;
                    m = tmp;
                }
            }
            ans+=m;
        }
        ans+=rev(s.substring(idx));
        System.out.print(ans);
    }
    private static String rev(String s) {
        return s.chars().mapToObj(c -> ""+(char) c)
                .reduce("", (acc, a)->a+acc);
    }
}
