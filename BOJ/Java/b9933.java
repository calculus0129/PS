import java.io.*;

public class b9933 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        String[] s = new String[n];
        for(int i=0;i<n;++i) {
            s[i] = br.readLine();
            if(ispalindrome(s[i])) {
                System.out.printf("%d %c", s[i].length(), middle(s[i]));
            }
        }
        for(int i=0, j;i<n;++i) for(j=i+1;j<n;++j) {
            if(matches(s[i], s[j])) System.out.printf("%d %c", s[i].length(), middle(s[i]));
        }

    }

    private static char middle(final String s) {
        return s.charAt(s.length()>>1);
    }

    private static String reverse(final String s) {
        final String[] ret = {""};
        s.chars().forEach(a -> {
            ret[0] = (char)a + ret[0];
        });
        return ret[0];
    }

    private static boolean ispalindrome(final String s) {
//        System.out.println(reverse(s));
        return s.equals(reverse(s));
    }

    private static boolean matches(final String s1, final String s2) {
        return reverse(s1).equals(s2);
    }
}
