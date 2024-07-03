#include <bits/stdc++.h>
using namespace std;
bool arr[2001][2001];
int ans;
int n;
struct cross {
    int cx, cy, len;
};

queue<cross> que;

void input() {
    cin >> n;
    for(int i=0,j;i<n;++i) for(j=0;j<n;++j) {
        char c;
        cin >> c;
        arr[i][j] = c-'0';
    }
}

bool push(int cx, int cy, int size) {
    if(cx+size>=n || cy+size >= n || cx-size<0 || cy-size<0) return false;
    bool ret = true;
    for(int i=0;i<(size<<1);++i) {
        if(i!=size) {
            if(arr[cx-size+i][cy-size] || arr[cx+size][cy-size+i] || arr[cx+size-i][cy+size] || arr[cx-size][cy+size-i]) {
                ret = false;
                break;
            }
        } else if (!(arr[cx][cy-size] && arr[cx+size][cy] && arr[cx][cy+size] && arr[cx-size][cy])) {
            ret=false;
            break;
        }
    }
    if(ret) {
        que.push({cx, cy, size});
        ++ans;
    }
    return true;
}

void init() {
    for(int i=1,j;i<n-1;++i) for(j=1;j<n-1;++j) if(arr[i][j]) push(i, j, 1);
}

void work() {
    while(!que.empty()) {
        cross f = que.front(); que.pop();
        push(f.cx, f.cy, f.len+1);
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    input();
    init();
    work();
    // for(int i=0;i<n;++i) if(ans[i]) ++a;
    cout << ans;
    return 0;
}