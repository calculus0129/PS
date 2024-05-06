#include <bits/stdc++.h>
using namespace std;

enum node_label {
    UNDISCOVERED,
    DISCOVERED,
    FINISHED
};

class Node {
    public:
    int id;
    node_label state;
    Node(int id)
    : id(id), state{(node_label)UNDISCOVERED} {}

    bool operator<(const Node &n) const {
        return id<n.id;
    };
};

// https://blog.naver.com/white_winter_fox/223108534072
enum edge_label {
    // UNDISCOVERED,
    DISCOVERY=1,
    BACK
};

class Edge {
    Node *u, *v; // u: initial, v: terminal point
    public:
    edge_label state;
    Edge(Node *u, Node *v)
    : u(u), v{v}, state{(edge_label)UNDISCOVERED} { }
    Node* opposite(Node *from) {
        return from == u ? v : u;
    }
};

unordered_map<Node*, vector<Edge*>> graph;
unordered_map<int, Node*> V;
unordered_map<Node*, vector<Node*>> tree, back_map;

int v, e;
set<int> roots;
set<int> ans;

void addEdge(int a, int b) {
    graph[V[a]].push_back(new Edge(V[a], V[b]));
    graph[V[b]].push_back(new Edge(V[b], V[a]));
}

void input() {
    cin >> v >> e;
    for(int i=1;i<=v;++i) {
        Node* p = new Node(i);
        V[i]=p;
        graph[p] = vector<Edge*>();
        tree[p] = vector<Node*>();
        back_map[p] = vector<Node*>();
    }
    for(int i=0, a, b;i<e;++i) {
        cin >> a >> b;
        addEdge(a, b);
    }
}

int dTime[10101], lTime[10101];

// variable shadowing works in C++17?
int dfs(Node *v, int timer) {
    v->state = DISCOVERED;
    dTime[v->id] = ++timer;
    Node *to;

    for(Edge* e: graph[v]) if(e->state == UNDISCOVERED) {
        to = e->opposite(v);
        if(to->state == UNDISCOVERED) {
            tree[v].push_back(to);
            e->state = DISCOVERY;
            timer = dfs(to, timer);
        }
        else {
            back_map[v].push_back(to);
            e->state = BACK;
        }
    }

    return ++timer;
}

// variable shadowing works in C++17?
void low_update(Node *u) {
    int id = u->id;
    int low_value = INT_MAX;
    for(Node *v : tree[u]) {
        low_update(v);
        low_value = min(low_value, lTime[v->id]);
    }
    for(Node *v : back_map[u]) {
        low_value = min(low_value, dTime[v->id]);
    }
    lTime[id] = low_value;
}

void dfs_traversal() {
    int timer=0;
    for(int i=1;i<=v;++i) if(V[i]->state == UNDISCOVERED) {
        roots.insert(i);
        timer = dfs(V[i], timer);
    }
    for(int i=1;i<=v;++i) if(lTime[i]==0) low_update(V[i]);
}

void find_articulations() {
    bool r;
    int c;
    for(int i=1;i<=v;++i) {
        r = false;
        if(roots.find(i) == roots.end()) {
            // variable shadowing works?
            for(Node* v: tree[V[i]]) {
                c = v->id;
                if(lTime[c]>=dTime[i]) {
                    r = true;
                    break;
                }
            }
        }
        else {
            // comparison precedes assignment.
            r = tree[V[i]].size() > 1;
        }
        if(r) ans.insert(i);
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    input();
    dfs_traversal();
    find_articulations();
    cout << ans.size() << '\n';
    for(int n: ans) {
        cout << n << ' ';
    }

    return 0;
}