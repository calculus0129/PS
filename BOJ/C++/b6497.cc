#include <bits/stdc++.h>
using namespace std;
int m, s[200001];

struct edge {
    int a, b, w;
};

bool cmp(const edge &x, const edge &y) {
    return x.w>y.w;
}

int find(int a) {
    if(s[a] == a) return a;
    return s[a] = find(s[a]);
}

int unionize(int a, int b) {
    int fa = find(a), fb = find(b);
    if(fa != fb) return s[fa] = s[fb] = min(fa, fb);
    return fa;
}

priority_queue<edge, vector<edge>, bool(*)(const edge &, const edge &)> pq(cmp);

//map<int, vector<edge>> graph;

void make_set(int i) {
    s[i] = i;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int m, n, a, b, c, ans, edge_sum, remaining_edge;
    edge f;
    cin >> m >> n;
    while(m!=0) {
        remaining_edge = m-1;
        ans = edge_sum = 0;
        for(int i=0;i<m;++i) make_set(i);
        for(;n>0;--n) {
            cin >> a >> b >> c;
            /*graph[a].push_back({a, b, c});
            graph[b].push_back({b, a, c});*/
            ans += c;
            pq.push({a, b, c});
        }
        while(remaining_edge>0) {
            f = pq.top(), a = f.a, b = f.b, c = f.w;
            pq.pop();
            if(find(a)==find(b)) continue;
            --remaining_edge;
            unionize(a, b);
            edge_sum += c;
        }

        cout << ans - edge_sum << '\n';
        pq = priority_queue<edge, vector<edge>, bool(*)(const edge &, const edge &)>(cmp);

        cin >> m >> n;
    }
    

    return 0;
}