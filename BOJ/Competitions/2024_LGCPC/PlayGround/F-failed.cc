#include <bits/stdc++.h>
using namespace std;

// later!
struct ford_fulkerson {
    struct label {
        bool plus;
        int from;
        int z;
    };
    // 1~n (max: 10000): 지원자
    // 0: source
    // 10001-10003: 강당
    // 10004: sink
    const int n;
    unordered_map<int,int> cap[10005], flow[10005];
    set<int> g[10005];
    vector<int> wg[10005];
    label labels[10005];
    ford_fulkerson(int n) : n(n) {
        cap[0].rehash(10005);
        flow[0].rehash(10005);
        for (int i = 0; i < 10005; i++) {
            g[i].clear();
            wg[i].clear();
            // memset(cap[i], 0, sizeof(cap[i]));
            // memset(flow[i], 0, sizeof(flow[i]));
        }
    }
    void addEdge(int a, int b, int c) {
        g[a].insert(b);
        wg[a].push_back(b);
        wg[b].push_back(a);
        cap[a][b] = c;
    }

    int dfs(int a, int z) {
        if(a == 10004) return z;
        for(int b: wg[a]) if(!labels[b].z && cap[a][b] > flow[a][b]) {
            labels[b] = {true, a, min(labels[a].z, cap[a][b] - flow[a][b])};
            int df = dfs(b, labels[b].z);
            if(df) return df;
        }
        return 0;
    }
    // returns if there is an augmenting path
    bool labelandscan() {
        memset(labels, 0, sizeof(labels));
        labels[0] = {false, -1, 0x7fffffff};
        return dfs(0, -1);
    }
    int augmentflow() {
        int z = labels[10004].z;
        for(int x = 10004;x;x = labels[x].from) {
            if(labels[x].plus) {
                flow[labels[x].from][x] += z;
            } else {
                flow[x][labels[x].from] -= z;
            }
        }
        return z;
    }
    int maxflow() {
        int ret = 0;
        while(labelandscan()) {
            ret += augmentflow();
        }
        return ret;
    }
    void solve() {
        cout << maxflow() << '\n';
        for(int i=1;i<=n;++i) for(int j=1;j<=3;++j) if(flow[i][10000+j]) {
            cout << i << ' ' << (char)('A'+j-1) << '\n';
        }
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false); // Speed up IO
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        ford_fulkerson ff(n);
        for(int i=1;i<=n;++i) {
            ff.addEdge(0, i, 1);
        }
        for(int i=1, a;i<=3;++i) {
            cin >> a;
            ff.addEdge(10000+i, 10004, a);
        }
        for(int i=1,a,b;i<=3;++i) {
            cin >> a;
            while(a--) {
                cin >> b;
                ff.addEdge(b, 10000+i, 1);
            }
        }
        ff.solve();
    }
    return 0;
}