#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string s;
    getline(cin, s);
    int ph = 0, pg = 0;
    for(char c: s) {
        switch(c) {
            case 'H':
            case 'P':
            case 'Y':
                ph++;
                break;
            case 'S':
            case 'D':
                pg++;
                break;
            case 'A':
                ph++;
                pg++;
        }
    }
    // double percentage = 0.5;
    // cout << fixed << setprecision(2);
    // cout << percentage*100;
    if(ph+pg != 0) {
        int q = 10000*ph/(ph+pg), r = 10000*ph%(ph+pg);
        if((r<<1)>=ph+pg) q++;
        cout << q/100 << '.' << setw(2) << setfill('0') << q%100;
    } else cout << "50.00";
    return 0;
}
// https://www.acmicpc.net/board/view/129147 헉
// H SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS ==> 3.125%. 답: 3.13