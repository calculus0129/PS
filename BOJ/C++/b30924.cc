#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dtb(0, 9999);
    int sa = dtb(gen), sb = dtb(gen), a=0, b=0;
    for(int i=0,resp=0;!resp && i<9998;++i) {
        cout << "? A " << (i+sa)%10000+1 << endl;
        cin >> resp;
        if(resp) {
            a = (i+sa)%10000+1;
        }
    }
    for(int i=0,resp=0;!resp && i<9998;++i) {
        cout << "? B " << (i+sb)%10000+1 << endl;
        cin >> resp;
        if(resp) {
            b = (i+sb)%10000+1;
        }
    }
    if(a==0 && b==0 || a == 0) {
        cout << "? A " << (sa+9998)%10000+1 << endl;
        int resp;
        cin >> resp;
        if(resp) a = (sa+9998)%10000+1;
        else a = (sa+9999)%10000+1;
        if(b == 0) b = (sb+9998+(dtb(gen)&1))%10000+1;
    } else if(b == 0) {
        cout << "? B " << (sb+9998)%10000+1 << endl;
        int resp;
        cin >> resp;
        if(resp) b = (sb+9998)%10000+1;
        else b = (sb+9999)%10000+1;
    }
    cout << "! " << a+b << endl;

    return 0;
}