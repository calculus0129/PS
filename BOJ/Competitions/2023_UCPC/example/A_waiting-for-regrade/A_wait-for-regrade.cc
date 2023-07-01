#include <bits/stdc++.h>
int max_match, arr[20], ans[20], n;
using namespace std;
int match() {
    int ret=0;
    for(int i=0;i<n;++i) if(ans[i]==arr[i]) ++ret;
    return ret;
}

void push(int pos) {
    for(int i=n-1;i>pos;--i) {
        arr[i]=arr[i-1];
    }
    arr[pos]=0;
}

void pull(int pos) {
    for(int i=pos;i<n-1;++i) {
        arr[i]=arr[i+1];
    }
    arr[n-1]=0;
}

void work(int step) {
    if(step==0) {
        max_match = max(max_match, match());
        return;
    }
    int c_arr[20], pos;
    memcpy(c_arr, arr, sizeof(int)*n);
    for(pos=0;pos<n;++pos) {
        pull(pos);
        work(step-1);
        memcpy(arr, c_arr, sizeof(int)*n);
    }
    for(pos=0;pos<n;++pos) {
        push(pos);
        work(step-1);
        memcpy(arr, c_arr, sizeof(int)*n);
    }
}
int main() {
    // 총 2^3*20H3번 시도하면 되게끔! => Time Complexity: Okay.
    // Change: 총 20PI3*2^3회 시도하면 되도록..!
    // Since,  e.g. 뒤에서 당기고 앞에서 미는거랑
    // 앞에서 밀고 뒤에서 당기는 거랑 다를 수 있기 때문! (For Example.)
    cin.tie(0)->sync_with_stdio(0);
    int i, k;
    cin >> n >> k;
    for(i=0;i<n;++i) cin >> ans[i];
    for(i=0;i<n;++i) cin >> arr[i];
    for(i=0;i<=k;++i) work(i);
    cout << max_match;
    return 0;
}