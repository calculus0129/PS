#include <bits/stdc++.h>
using namespace std;
deque<int> arr;
bool visited[30001];
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int w; cin >> w;
    int n; cin >> n;
    arr.resize(n);
    for(int i=0;i<n;++i) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int cap=0, ans=0;
    int cnt=0;
    while(!arr.empty()) {
        auto ptr = upper_bound(arr.begin(), arr.end(), cap);
        if(cnt > 1 || ptr == arr.begin()) {
            ++ans;
            cap = w;
            cnt = 0;
        } else {
            --ptr;
            cap -= *ptr;
            arr.erase(ptr);
            ++cnt;
        }
    }
    
    cout << ans;
    return 0;
}