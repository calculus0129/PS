#include <bits/stdc++.h>
using namespace std;

bool verify(int num) {
    vector<int> arr;
    arr.reserve(20);
    bool r;
    for(int b=2,t,n,i;b<=64;++b) {
        t=num;
        r=true;
        arr.clear();
        while(t) {
            arr.push_back(t % b);
            t /= b;
        }
        n=arr.size();
        for(i=0;i<(n>>1);++i) {
            if(arr[i] ^ arr[n-1-i]) {
                r = false;
                break;
            }
        }
        if(r) {
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    int n;
    while(T--) {
        cin >> n;
        cout << verify(n) << '\n';
    }

    return 0;
}