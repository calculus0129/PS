#include <bits/stdc++.h>
// https://www.acmicpc.net/blog/view/106
#define X first
#define Y second
#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
ll ans;
bool arr[303030];

pair<vector<ll>, vector<ll>> input() {
    int n;
    ll c1, c2;
    cin >> n >> c1 >> c2;
    // scanf("%d %lld %lld", &n, &c1, &c2);
    queue<pii> pos;
    vector<ll> vv{0LL}, ev{0LL};
    char c;
    for(int i=0;i<n;++i) {
        // scanf(" %c", &c);
        cin >> c;
        arr[i] = c == '1';
    }
    for(int i=0,j=0;i<n;i=j) {
        if(!arr[i]) {
            ++j;
            continue;
        }
        while(j<n && arr[j]) ++j;
        pos.push({i,j});
    }
    if(pos.empty()) return {vv, ev};
    pii p = pos.front(); pos.pop(); vv.push_back((p.second-p.first)*c2);
    while(!pos.empty()) {
        ev.push_back((pos.front().first - p.second)*c1);
        p = pos.front(); pos.pop();
        vv.push_back((p.second - p.first) * c2);
    }
    return {vv, ev};
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
	int T, test_case;
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
	// scanf("%d", &T);
	for(test_case = 0; test_case  < T; test_case++)
	{
		ans = 0LL;
		/////////////////////////////////////////////////////////////////////////////////////////////
        auto [vv, ev] = input();
        int n = vv.size()-1; //ev.push_back(0LL);
        vector<vector<ll>> dp(n+1, vector<ll>(4, 0LL));
        if(n>1) {
            dp[1][0] = vv[1];
            dp[1][1] = 0LL;
            dp[1][2] = LONG_MAX;
        }
        for(int i=2;i<=n;++i) {
            dp[i][0] = dp[i-1][0] + vv[i];
            dp[i][1] = min(dp[i-1][0], dp[i-1][1] + ev[i-1]);
            dp[i][2] = min(dp[i-1][1], dp[i-1][2])+vv[i];
            dp[i][3] = min(min(dp[i][0], dp[i][1]), dp[i][2]);
        }
        ans = dp[n][3];
        
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << '\n';
		cout << ans << '\n';
	}

    return 0;
}