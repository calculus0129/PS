import java.util.Scanner;

class Point {
    double x, y;
    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }
    double dist(Point other) {
        return Math.sqrt((x-other.x)*(x-other.x)+(y-other.y)*(y-other.y));
    }
    double[] slope(Point other) {
        double dx = x - other.x, dy = y - other.y;
        return new double[]{dx, dy};
    }
}
public class b1064 {
    static Scanner sc = new Scanner(System.in);
    static Point a, b, c;
    public static void main(String[] args) {
        a = new Point(sc.nextDouble(), sc.nextDouble());
        b = new Point(sc.nextDouble(), sc.nextDouble());
        c = new Point(sc.nextDouble(), sc.nextDouble());
        double da = b.dist(c), db = c.dist(a), dc = a.dist(b), mx = Math.max(da, Math.max(db, dc)), mn = Math.min(da, Math.min(db, dc));
        //if(da==db+dc || db==dc+da || dc==da+db) System.out.println(-1);
        if(da==0||db==0||dc==0) System.out.println(-1);
        else {
            double[] alpha = a.slope(b);
            double[] beta = b.slope(c);
            if(alpha[0]*beta[1] == alpha[1]*beta[0]) System.out.println(-1);
            else System.out.println((mx - mn) * 2);
        }
    }
}
