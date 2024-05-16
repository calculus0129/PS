#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, sum, t=0;
    string stu[101];
    cin >> n;// cin은 버퍼에 엔터가 남아있음.
    while(n) {
        sum=0;
        char c;
	    cin.ignore(); // 입력 버퍼 비우기
        for(int i=1;i<=n;++i) {
            getline(cin, stu[i]);
            sum += i<<1;
        }
        for(int i=0, a;i<2*n-1;++i) {
            cin >> a >> c;
            sum -= a;
        }
        cout << ++t << ' ' << stu[sum] << '\n';
        cin >> n;
    }
    return 0;
}