#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    vector<int> arr;
    int a, n;
    while(cin >> a) arr.push_back(a);
    arr.pop_back();
    sort(arr.begin(), arr.end());
    n = arr.size();
    int cnt=0;
    set<pair<int,int>> see;
    for(int i=0,j;i<n;++i) for(j=i+1;j<n;++j) if(arr[i]+arr[j]==a && see.find({arr[i], arr[j]})==see.end()) {
        ++cnt;
        cout << arr[i] << ' ' << arr[j] << '\n';
        see.insert({arr[i], arr[j]});
    }
    cout << cnt;

    return 0;
}