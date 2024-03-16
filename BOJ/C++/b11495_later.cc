#include <bits/stdc++.h>
using namespace std;
int m, n;
int arr[50][50];



void init_graph() {

}

bool labelandscan() {

}

int augmentflow() {
    int ret=0;
    return ret;
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t;
    for(cin >> t;t>0;--t) {
        cin >> m >> n;
        for(int i=0,j;i<m;++i) for(j=0;j<n;++j) cin >> arr[i][j];
        init_graph();
        int ans=0;
        while(labelandscan()) ans += augmentflow();

    }
    return 0;
}