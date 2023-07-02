#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, i;
    cin >> n;
    int arr[201]={};
    while(n--) {
        cin >> i;
        arr[i+100]++;
    }
    cin >> i; cout << arr[i+100];
    return 0;
}