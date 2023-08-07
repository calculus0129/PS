#include <bits/stdc++.h>
using namespace std;
int arr[10];
int n, cost, l;
typedef pair<int,int> pii;
string ans;

bool lt(const pii &a, const pii &b) {
    return (a.second == b.second) ? a.first > b.first : a.second < b.second;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int i, j, c;
    vector<pii> vec;
    for(i=0;i<n;++i) {
        cin >> arr[i];
        vec.push_back(make_pair(i, arr[i]));
    }
    sort(vec.begin(), vec.end(), lt);
    cin >> cost;
    if(n==1) {
        cout << 0;
        return 0;
    }
    if(vec[0].first == 0 && vec[1].second <= cost) {
        ans += '0'+vec[1].first;
        cost -= vec[1].second;
    } else {
        if(vec[0].first == 0) {
            cout << 0;
            return 0;
        }
        ans += '0' + vec[0].first;
        cost -= vec[0].second;
    }
    while(cost >= vec[0].second) {
        ans += '0' + vec[0].first;
        cost -= vec[0].second;
    }
    l = ans.size();
    for(i=0;i<l;++i) {
        c = ans[i]-'0';
        for(j=n-1;j>=c;--j) {
            if(cost + arr[c] >= arr[j]) {
                ans[i] = '0' + j;
                cost -= arr[j] - arr[c];
                break;
            }
        }
    }
    cout << ans;

    return 0;
}