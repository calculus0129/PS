#include <bits/stdc++.h>
using namespace std;
class tree {
    public:
    int r, d;
    vector<int> dist, depth;
    vector<tree*> C;
    //tree* parent;
    void add(tree&, int);
    void update(tree*);
    void find_d_and_r();
    tree() : r(0), d(0) {}
};

void tree::add(tree& neighbor, int w) {
    C.push_back(&neighbor);
    dist.push_back(w);
}

void tree::update(tree* from) {
    int p = find(C.begin(), C.end(), from) - C.begin();
    //parent = C[p];
    C.erase(C.begin()+p);
    dist.erase(dist.begin()+p);
    for(tree* x: C) {
        x->update(this);
    }
}

void tree::find_d_and_r() {
    for(tree* x: C) x->find_d_and_r();
    int s = C.size(), d1=0, d2=0;
    if(s==0) return;
    depth.resize(s);
    for(int i=0;i<s;++i) {
        depth[i] = dist[i]+C[i]->r;
        d2 = max(d2, C[i]->d);
    }
    auto tmp = max_element(depth.begin(), depth.end());
    r = *tmp;
    *tmp = 0;
    d1 = r + *max_element(depth.begin(), depth.end());
    d = max(d1, d2);
    *tmp = r;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, n, i=0, v, w;
    cin >> n;
    tree* T = new tree[n+1];
    while(i++<n) {
        cin >> a;
        cin >> v;
        while(v!=-1) {
            cin >> w;
            T[a].add(T[v], w);
            cin >> v;
        }
    }
    // Consider T[1] as the root.
    for(tree* x: T[1].C) x->update(&(T[1]));
    T[1].find_d_and_r();
    cout << T[1].d;
    delete[] T;

    return 0;
}