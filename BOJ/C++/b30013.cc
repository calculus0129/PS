#include <bits/stdc++.h>
using namespace std;
int n, ans;
bool arr[2002];

int solve(int step) {
    int ret = 0;
    bool brr[2002];
    memcpy(brr, arr, sizeof(arr));
    for(int i=0, j;i<n;++i) if(brr[i]) {
        ++ret;
        for(j=i;j<n && brr[j];j+=step) brr[j] = false;
    }
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    string s;
    cin >> s;
    int i=0;
    for(const char *c=s.c_str();*c!='\0';++c) {
        arr[i++] = *c == '#';
    }

    ans = n;
    for(int i=1, a;i<=n;++i) {
        a = solve(i);
        if(a<ans) ans = a;
    }
    cout << ans;

    return 0;
}