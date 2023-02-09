#include <bits/stdc++.h>
using namespace std;
class tree {
public:
    int d=0, h=0;
    tree* parent;
    vector<pair<tree*, int>> children;
    tree() {}
    tree(vector<pair<tree*,int>> neighbors)
    : children(neighbors) {}
    void findparents();
    void tree_dh();
};

void tree::findparents() {
    for(auto i: children) {
        i.first->parent = this;
        for(auto j = i.first->children.begin(), e = i.first->children.end();j!=e;++j) if(j->first == this)
        {
            i.first->children.erase(j);
            break;
        }
        i.first->findparents();
    }
}

void tree::tree_dh() {
    if(children.empty()) return;
    for(auto i: children) {
        i.first->tree_dh();
    }
    int n = children.size();
    vector<int> h_vec(n, 0), d_vec(n, 0);
    for(int i=0;i<n;++i)
    {
        h_vec[i] = children[i].first->h + children[i].second;
        d_vec[i] = children[i].first->d;
    }
    auto m = max_element(h_vec.begin(), h_vec.end());
    h = *m;
    *m = 0;
    d = max(*max_element(d_vec.begin(), d_vec.end()), h+*max_element(h_vec.begin(), h_vec.end()));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, n, w;
    cin >> n;
    tree *p = new tree[n+1];
    for(int _=0;_<n;++_) {
        cin >> a;
        while(1) {
            cin >> b;
            if(b==-1) break;
            cin >> w;
            p[a].children.push_back({&p[b], w});
            p[b].children.push_back({&p[a], w});
        }
    }
    p[1].findparents();
    p[1].tree_dh();
    cout << p[1].d;

    return 0;
}

/*#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

struct edge
{
    int vertex, weight;
};
vector<vector<edge>> graph;
vector<int> visited, h, l;

void bfs()
{
    int i,e;
    int f;
    vector<edge> *tmp;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        f=q.front();
        q.pop();
        visited.push_back(f);
        tmp=&(graph[f]);
        for(i=0,e=tmp->size();i!=e;++i)
        {
            q.push(((*tmp)[i]).vertex);
        }
    }
}

void calculate()
{
    vector<int> vl, vh;
    vector<edge> *tmp;
    int j,e,h1,h2;
    vl.reserve(MAX);
    vh.reserve(MAX);
    for(auto i=visited.rbegin(), ii=visited.rend();i!=ii;++i)
    {
        vl.clear();
        vh.clear();
        tmp=&(graph[*i]);
        for(j=0,e=tmp->size();j!=e;++j)
        {
            vh.push_back((*tmp)[j].weight+h[j]);
            vl.push_back(l[j]);
        }
        auto ptr=max_element(vh.begin(), vh.end());
        h1=*ptr;
        *ptr=0;
        ptr=max_element(vh.begin(), vh.end());
        h2=*ptr;
        h[*i] = h1;
        l[*i] = max(h1+h2, *max_element(vl.begin(), vl.end()));
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int v,i,a,b,w;
    cin >> v;
    graph.resize(v+1);
    h.resize(v+1);
    l.resize(v+1);
    i=v;
    while(i--)
    {
        cin >> a;
        while(1)
        {
            cin >> b;
            if(b==-1) break;
            cin >> w;
            graph[a].push_back(edge{b, w});
        }
    }
    bfs();
    calculate();
    cout << l[1];

    return 0;
}*/
