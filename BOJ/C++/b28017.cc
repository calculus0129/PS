#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

// vector<pii> arr[501];
int arr[501][501];
int n, m, ans[501];

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0, j;i<n;++i) {
        for(j=0;j<m;++j) {
            cin >> arr[i][j];
        }
    }
    vector<pii> brr; brr.reserve(501);
    for(int i=1,j;i<n;++i) {
        brr.clear();
        for(j=0;j<m;++j) brr.push_back({arr[i-1][j], j});
        sort(brr.begin(), brr.end(), [](const pii &a, const pii &b) -> bool {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });
        for(j=0;j<m;++j) arr[i][j] += (brr[0].second == j) ? brr[1].first : brr[0].first;
    }
    cout << *min_element(arr[n-1], arr[n-1]+m);

    return 0;
}