import java.util.Scanner;


class SLL<T> {
    public class Node<T> {
        T datum;
        Node<T> next = null;
        Node (T t) {
            datum = t;
        }
        Node (T t, Node<T> tail) {
            datum = t;
            next = tail;
        }
    }
    Node<T> head = null;
    int size = 0;
    SLL() {}
    final T poll() {
        return head.datum;
    }
    void add(T t) {
        head = new Node<>(t, head);
        ++size;
    }
    T pop() {
        T ret = head.datum;
        head = head.next;
        --size;
        return ret;
    }
}

public class b17608 {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt();
        SLL<Integer> stack = new SLL<>();
        for(int i=0, a;i<n;++i) {
            a = sc.nextInt();
            while(stack.size>0 && stack.poll()<=a) stack.pop();
            stack.add(a);
        }
        System.out.println(stack.size);
    }
}
