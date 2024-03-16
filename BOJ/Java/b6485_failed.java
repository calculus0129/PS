import java.io.*;
import java.util.Map;
import java.util.TreeMap;

class Item {
    int buyat, sellat; // in cents

    Item(int buyat, int sellat) {
        this.buyat = buyat;
        this.sellat = sellat;
    }
}

public class b6485_failed {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static Map<String, Integer> inventory = new TreeMap<>();
    static Map<String, Item> items = new TreeMap<>();
    static int profit=0; // in cents.

//    static {
//        try {
//            bw = new BufferedWriter(new FileWriter("b6485_output.txt"));
//        } catch (IOException e) {
//            throw new RuntimeException(e);
//        }
//    }

    static String report() {
        int n, val = 0, tval;
        String tmp;
        String ret = "                  INVENTORY REPORT\nItem Name     Buy At      Sell At      On Hand        Value\n---------     ------      -------      -------        -----\n";
        for(String s: inventory.keySet()) {
            n = 20;
            ret += s;
            Item ite = items.get(s);
            tmp = String.format("%.2f", ite.buyat*0.01);
            n -= s.length() + tmp.length();
            while(n-->0) ret += " ";
            ret += tmp;

            n = 13;
            tmp = String.format("%.2f", ite.sellat*0.01);
            n -= tmp.length();
            while(n-->0) ret += " ";
            ret += tmp;

            n = 13;
            tmp = Integer.toString(inventory.get(s));
            n -= tmp.length();
            while(n-->0) ret += " ";
            ret += tmp;

            n = 13;
            tval = ite.buyat*inventory.get(s);
            val += tval;
            tmp = String.format("%.2f", tval*0.01);
            n -= tmp.length();
            while(n-->0) ret += " ";
            ret += tmp;

            ret+='\n';
        }
        ret += "------------------------\n";

        ret += "Total value of inventory";
        n = 35;
        tmp = String.format("%.2f", val*0.01);
        n -= tmp.length();
        while(n-->0) ret += " ";
        ret += tmp;

        ret += "\nProfit since last report";
        n = 35;
        tmp = String.format("%.2f", profit*0.01);
        n -= tmp.length();
        while(n-->0) ret += " ";
        ret += tmp;

        profit = 0;

        return ret;
    }

    public static void main(String[] args) throws IOException{
        boolean first = true;
//        for(int i=-5;i!=6;++i) System.out.println(i%5);
        String s = br.readLine();
        while(!s.equals("*")) {
            String[] input = s.split(" ");
            if(input[0].equals("new")) {
                items.put(input[1], new Item((int)(Double.parseDouble(input[2])*100), (int)(Double.parseDouble(input[3])*100)));
                inventory.put(input[1], 0);
            } else if(input[0].equals("delete")) {
                profit-=items.get(input[1]).buyat * inventory.get(input[1]);
                items.remove(input[1]);
                inventory.remove(input[1]);
            } else if(input[0].equals("buy")) {
                inventory.put(input[1], inventory.get(input[1]) + Integer.parseInt(input[2]));
            } else if(input[0].equals("sell")) {
                int quantity = Integer.parseInt(input[2]);
                inventory.put(input[1], inventory.get(input[1]) - quantity);
                profit += (items.get(input[1]).sellat - items.get(input[1]).buyat) * quantity;
            } else { // report
                if(first) first=false;
                else bw.write("\n\n");
                bw.write(report());
            }
            s = br.readLine();
        }
        bw.close();
    }
}
