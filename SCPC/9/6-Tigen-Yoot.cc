/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mov[100][6];
bool circ[100][6];
vector<int> arr;
int pos;
ll r;

int yoot[101], arrival[101];
pair<int,bool> mv(int pos, int dice) {
    while(dice--) pos = yoot[pos];
    pos = arrival[pos];
    return {pos==100?0:pos, pos==100};
}

void init() {
    unordered_set<int> start = {5,10,22};
    // path 0
    for(int i=0;i<19;++i) yoot[i] = i+1;
    yoot[19]=29;
    
    // path 1
    yoot[100-5] = 20;
    for(int i=20;i<24;++i) yoot[i] = i+1;
    yoot[24] = 15;

    // path 3 & 2
    yoot[100-10]=25;
    yoot[25]=26;
    yoot[26]=100-22;
    yoot[100-22]=27;
    yoot[27]=28;
    yoot[28]=29;
    yoot[29]=100;
    yoot[100]=100;

    // arrival
    for(int i=0;i<=29;++i) arrival[i] = i;
    arrival[100]=100;
    for(int i: start) {
        arrival[i]=100-i;
    }
    arrival[100-22]=100-22;

    // move
    for(int i=0,j;i<100;++i) {
        mov[i][0] = i;
        for(j=1;j<=5;++j) {
            auto p = mv(i, j);
            mov[i][j] = p.first;
            circ[i][j] = p.second;
        }
    }
}
int visited[100];
ll cr[100];

void work(int k) {
    pos = 0;
    r = 0LL;
    memset(visited, 0, sizeof(visited));
    int cycle=0;
    while (cycle<k) {
        if(visited[pos]) break;
        visited[pos] = cycle;
        cr[pos] = r;
        for(int i: arr) {
            if(circ[pos][i]) ++r;
            pos = mov[pos][i];
        }
        ++cycle;
    }
    k -= cycle;
    cycle -= visited[pos];
    ll rcycle = r - cr[pos];

    // cout << "cycle: " << cycle << ", rcycle: " << rcycle << '\n';
    if(cycle<k) {
        r += rcycle*(k/cycle);
        k%=cycle;
    }
    while(k--) 
        for(int i: arr) {
            if(circ[pos][i]) ++r;
            pos = mov[pos][i];
        }
}

int main(int argc, char** argv)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
	int T, test_case;
    arr.reserve(100002);
    init();
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int n, k;
        cin >> n >> k;
        arr = vector<int>(n);
        for(int i=0;i<n;++i) cin >> arr[i];

        work(k);
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << '\n';
		cout << r << '\n';
	}

	return 0;//Your program should return 0 on normal termination.
}