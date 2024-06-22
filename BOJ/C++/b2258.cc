#include <bits/stdc++.h>
#define X first
#define Y second
#define ALL(x) x.begin(), x.end()
using namespace std;
typedef pair<int,int> pii;
int n, m;

vector<pii> inp;

int main () {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m;
    inp.resize(n);
    for(int i=0;i<n;++i) {
        cin >> inp[i].X >> inp[i].Y;
    }
    // cost nondecreasing, amount nonincreasing order.
    sort(inp.begin(), inp.end(), [](const pii &a, const pii &b)->bool {
        return (a.second == b.second) ? a.first>b.first : a.second<b.second;
    });
    vector<int> costs(n, 0), real_costs(n, 0);
    for(int i=0;i<n;++i) costs[i] = real_costs[i] = inp[i].Y;
    costs.erase(unique(ALL(costs)), costs.end());

    int dum=0, amount, ans=-1;
    for(int cost: costs) {
        // i: the lower index of cost, e: the 'ending' index of cost.
        int i=lower_bound(ALL(real_costs), cost)-real_costs.begin();
        amount = dum + inp[i].X;
        // See if the cost is good.
        if(amount>=m) {
            ans = cost;
            break;
        }
        // Sum up to the dum.
        for(int e=upper_bound(ALL(real_costs), cost)-real_costs.begin();i!=e;++i) {
            dum += inp[i].X;
        }
    }
    if(ans == -1 && dum>=m) {
        int cost = real_costs[n-1], l = lower_bound(ALL(real_costs), cost) - real_costs.begin();
        int idx = n-1;
        while(dum-inp[idx].X>=m) {
            dum -= inp[idx].X;
            idx--;
        }
        ans = cost*(idx-l+1);
    }
    cout << ans;

    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// int n, m;
// map<int, int> gogis;
// map<int, int> dums;

// int main() {
//     cin.tie(NULL); ios_base::sync_with_stdio(false);
//     cin >> n >> m;
//     dums.insert({0,0});
//     for(int i=1, a, b;i<=n;++i) {
//         cin >> a >> b;
//         if(gogis.find(b)!=gogis.end()) {
//             gogis[b] = max(gogis[b], a); // maximum amount
//             dums[b] += a;
//         }
//         else {
//             gogis.insert({b, a});
//             dums.insert({b, a});
//         }
//     }
//     // sum up
//     for(auto p=dums.begin(), e=dums.end();++p!=e;) {
//         auto a = p; a--;
//         p->second += a->second;
//     }
//     // sum to the gogis
//     for(auto p=dums.begin(), e=dums.end();++p!=e;) {
//         auto a = p; a--;
//         gogis.find(p->first)->second += a->second;
//     }
//     // search for gogi with certain amount. (m) // linear search available
//     int ans=-1;
//     for(const auto &p: gogis) {
//         if(p.second>=m) {
//             ans = p.first;
//             break;
//         }
//     }
//     // print out the cost (.first)
//     cout << ans;

//     return 0;
// }