#include <bits/stdc++.h>
//#define MAX (1e4) // => error: invalid conversion from double to long long unsigned int.
const int MAX = 1e4;
using namespace std;
int n, d[MAX+1]; // d for diameter. d[i] : the diameter across node i. if i is a leaf node (i.e. degree=1), this should represent the maximum length of path starting from i.
struct edge {
    int t, w;
};
vector<edge> graph[MAX+1];

// this tech: inspired from https://www.acmicpc.net/source/36555949
// by parameter 'par', the solve() would return the maximal distance, but not including the ones from cur across par. => just what we need to fill in 'd[par]'.
// this should be able to cover...
// 1. the path from/across parental node, rooted from 1.
// 2. the path from/across some other nodes, excluding those directed from par. d[cur]
// ... but these would be considered by their parents! d[par] would consider that!
// d[cur] is covered only once when called by its parent.

// therefore, this can solve the problem!
int solve(int cur, int par) {
    int d1=0, d2=0, h; // d1 is max, d2 is the second max (if it exists.)
    for(auto i : graph[cur]) {
        if(i.t == par) continue;
        h = i.w + solve(i.t, cur);
        if(h>d1) {
            d2=d1;
            d1=h;
        }
        else if (h>d2)
        {
            d2=h;
        }
    }
    d[cur] = d1+d2;
    return d1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int a, b, w;
    for(int _=0;_<n-1;++_)
    {
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    solve(1, 0);
    cout << *max_element(d+1, d+n+1);

    return 0;
}
