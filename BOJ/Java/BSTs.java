import java.io.*;

public class BSTs {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    /*private interface Comparator<T> {
        public int compare(T a, T b);
    }*/

    private class bst<T extends Comparable<T>> {
        T datum;
        bst<T> par, left, right;
        boolean isNIL;
        bst() {
            this.isNIL = true;
            left = right = null;
        }
        bst<T> treeSearch(T x) {
            if(this.isNIL) return this;
            int comparison = this.datum.compareTo(x);
            if(comparison == 0) return this;
            else if(comparison<0) return right.treeSearch(x);
            else return left.treeSearch(x);
        }

        void add(T x) {
            bst<T> s = treeSearch(x);
            if(s.isNIL) s = new bst<>(x);
            else throw new IllegalStateException("This must not happen");
        }

        bst(T datum) {
            this.datum = datum;
            this.left = new bst<>();
            this.right = new bst<>();
            this.isNIL = false;
        }

    }

    public static void main(String[] args) throws IOException {

    }


}

