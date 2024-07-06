/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
// typedef pair<int, int> pi;
int n, stt, tgt, deg[300004];
bool discovered[300032];
unordered_map<int, vector<int>> graph;

void init() {
    stt=tgt=0;
    graph.clear();
    memset(discovered, 0, sizeof(discovered));
    // memset(visited, 0, sizeof(visited));
    memset(deg, 0, sizeof(deg));
}

void input() {
    init();
    cin >> n;
    int a, b;
    for(int i=0;i<=n;++i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    // stt << ' ' << tgt
    for(int i=1;i<=n;++i) {
        if(deg[i] == 3) {
            if(stt == 0) stt = i;
            else {
                tgt = i;
                break;
            }
        }
    }
    graph[stt].erase(find(ALL(graph[stt]), tgt));
    graph[tgt].erase(find(ALL(graph[tgt]), stt));
}

int work() {
    queue<int> q0,q1;
    queue<int> &que=q0, &tmp=q1;
    que.push(stt);
    int dist=0;
    while(!discovered[tgt]) { // !que.empty()
        swap(que, tmp);
        while(!tmp.empty()) {
            int u = tmp.front(); tmp.pop();
            for(int v: graph[u]) if(!discovered[v]) {
                discovered[v] = true;
                que.push(v);
            }
        }
        ++dist;
    }
    return dist-1;
}

ll ans(int n, int p) {
    ll ret = 0LL;
    ret += (ll)(p)*(p+1)>>1;
    ret += (ll)(n-1-p)*(n-2-p)>>1;
    return ret;
}

int main(int argc, char** argv)
{
	int T, test_case;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);
	cin >> T;
    graph.rehash(301010);
	for(test_case = 0; test_case  < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		// Print the answer to standard output(screen).
        input();
        int p = work();
		cout << "Case #" << test_case+1 << endl;
		cout << ans(n, p) << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}