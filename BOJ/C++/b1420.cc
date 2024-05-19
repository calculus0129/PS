#include <bits/stdc++.h>
using namespace std;
int m, n, s, t;
bool arr[101][101];
unordered_map<int, unordered_set<int>> graph;
unordered_map<int, unordered_map<int, int>> cap, flow;

// Let's think for each vertex in [i][j], its .in is (i*n+j)<<1, and .out is (i*n+j)<<1|1.
// Given a vth vertex, it represents [v/(n<<1)][(v>>1)%n] .in(v&1)else.out

struct label {
    bool plus;
    int from;
    int z;
};

label labels[20000];

void addEdge(int ain, int bin) {
    // Set capacities
    // from a.out to b.in
    cap[ain|1][bin]=10000;
    // from b.out to a.in
    cap[bin|1][ain]=10000;
    // Add the connection relation
    graph[ain|1].insert(bin);
    graph[bin|1].insert(ain);
    graph[ain].insert(bin|1);
    graph[bin].insert(ain|1);
}

void make_graph() {
    for(int i=0, j, ain;i<m;++i) for(j=0;j<n;++j) if(!arr[i][j]) {
        ain=n*i+j<<1;
        // Set self-capacity 1
        cap[ain][ain|1]=1;
        graph[ain].insert(ain|1);
        graph[ain|1].insert(ain);
        if(i<m-1 && !arr[i+1][j]) {
            addEdge(ain, n*(i+1)+j<<1);
        }
        if(j<n-1 && !arr[i][j+1]) {
            addEdge(ain, n*i+(j+1)<<1);
        }
    }
}

queue<int> que; // contains labeled vertices.
void scan(int u) {
    for(int v: graph[u]) if(labels[v].z==0) {
        if(cap[u][v]-flow[u][v]>0) {
            labels[v]={true, u, min({labels[u].z, cap[u][v]-flow[u][v]})};
            que.push(v);
        }
        else if(flow[v][u]>0) {
            labels[v]={false, u, min({labels[u].z, flow[v][u]})};
            que.push(v);
        }
    }
}

bool labelandscan() {
    memset(labels, 0, sizeof(labels));
    // fill(labels, &labels[20000], label({false, -1, 0}));
    labels[s]={true, -1, 10000};
    que=queue<int>();
    que.push(s);
    while(!que.empty() && labels[t].z==0) {
        scan(que.front()); que.pop();
    }
    return labels[t].z!=0; // returns whether the sink is labeled
}

int augmentflow() {
    int z = labels[t].z;
    for(int v=t,u=labels[t].from;v!=s;v=u,u=labels[u].from) {
        if(labels[v].plus) {
            flow[u][v] += z;
        }
        else {
            flow[v][u] -= z;
        }
    }
    return z;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> m >> n;
    char tmp[101];
    for(int i=0,j;i<m;++i) {
        memset(tmp, 0, sizeof(tmp));
        // cin.ignore();
        cin >> tmp;
        for(j=0;j<n;++j) switch(tmp[j]) {
            case '#':
                arr[i][j]=true;
                break;
            case 'K':
                s=(n*i+j)<<1|1;
                // s[0]=i,s[1]=j;
                break;
            case 'H':
                t=(n*i+j)<<1;
                // t[0]=i,t[1]=j;
                break;
        }
    }

    make_graph();

    int ans=0;
    while(labelandscan() && ans<10000) ans += augmentflow();
    cout << (ans<10000?ans:-1);
    // for(int i=0,j;i<m;++i) {
    //     for(j=0;j<n;++j) cout << (arr[i][j]?1:0) << ' ';
    //     cout << '\n';
    // }
    // cout << "s: " << s[0] << ", " << s[1] << '\n';
    // cout << "t: " << t[0] << ", " << t[1] << '\n';
    return 0;
}