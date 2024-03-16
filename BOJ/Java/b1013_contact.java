import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.concurrent.atomic.AtomicReference;

public class b1013_contact {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        while(t-->0) {
            bw.write((work(br.readLine())?"YES":"NO")+"\n");
        }
        bw.close();
    }
    private static boolean work(String arg) throws IOException {
        Deque<Character> deq = new ArrayDeque<>();
        boolean prev_one=false, pat1=false;
        int zero_cnt = 0;
        for(char c: arg.toCharArray()) {
            if(c=='0') {
                deq.addLast('0');
                zero_cnt++;
                if(deq.peekFirst() != '1' && prev_one && zero_cnt >= 2) deq.addFirst('1');
            }
            else {
                if(zero_cnt == 0) {
                    if(pat1) {
                        prev_one = true;
                        continue;
                    }
                    deq.add('1');
                } else if (zero_cnt == 1) {
                    deq.add('1');
                    if(ptnchk(deq, 2)) {
                        deq.clear();
                        prev_one = false;
                        zero_cnt = 0;
                        pat1 = false;
                    } else return false;
                } else {
                    deq.add('1');
                    if(ptnchk(deq, 1)) {
                        deq.clear();
                        prev_one = false;
                        zero_cnt = 0;
                        pat1 = true;
                    } else return false;
                }
            }
        }
        return deq.isEmpty();
    }
    private static boolean ptnchk(Deque<Character> deq, int pattern_no) {
        AtomicReference<String> s = new AtomicReference<>("");
        deq.stream().forEach(x-> {
            s.updateAndGet(v -> v + x);
        });

        if(pattern_no == 1) {
            return s.get().matches("100+1");
        } else {
            return s.get().equals("01");
        }
    }
}
