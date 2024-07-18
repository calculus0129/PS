#include <bits/stdc++.h>
using namespace std;
int arr[1001][1001];

void init() {

}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    init();
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << ceil((a-1)/(double)(b-1)) << '\n';
    }

    return 0;
}