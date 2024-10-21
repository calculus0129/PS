#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> p(m); for(int i=0;i<m;++i) cin >> p[i];
    sort(ALL(p), [](int a, int b) -> bool{
        return a>b;
    });
    vector<int> uprice = p;
    uprice.erase(unique(ALL(uprice)), uprice.end());
    int price=uprice.front(), income=0;
    for(int pr: uprice) {
        int newIncome = pr * min((long int)n, upper_bound(ALL(p), pr, greater<int>()) - p.begin());
        if(income <= newIncome) {
            price = pr;
            income = newIncome;
        }
    }
    cout << price << ' ' << income;

    return 0;
}