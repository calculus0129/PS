#include <bits/stdc++.h>
using namespace std;
int s[101010];

int find(int a) {
    if(a == s[a]) return a;
    return s[a] = find(s[a]);
}

bool uni(int a, int b) {
    int sa = find(a), sb = find(b);
    if(sa == sb) return true;
    s[sa] = s[sb] = min(sa, sb);
    return false;
}

struct Edge {
    int a,b,w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

int n, m;
priority_queue<Edge> pq;
bool r1, r2;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;++i) s[i] = i;
    int st, en;
    cin >> st >> en;
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({a, b, c});
    }
    int ans = 0;
    while(!pq.empty() && find(st) != find(en)) {
        Edge e = pq.top(); pq.pop();
        int a=e.a, b=e.b, c=e.w;
        if(!uni(a, b)) ans = c;
    }
    cout << (find(st) == find(en)?ans:0);
    
    return 0;
}