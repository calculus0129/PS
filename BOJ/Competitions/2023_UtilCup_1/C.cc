#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0;i<n;++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end(), greater<int>());
    int lsum=0, asum=0;
    for(int i=0, e = min(42, (int)vec.size()), a, l;i<e;++i) {
        lsum += (l = vec[i]);
        if(l>=250) a = 5;
        else if(l>=200) a = 4;
        else if(l>=140) a = 3;
        else if(l>=100) a = 2;
        else if(l>=60) a = 1;
        else a = 0;
        asum += a;
    }
    cout << lsum << ' ' << asum;

    return 0;
}