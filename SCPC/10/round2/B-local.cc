#include <bits/stdc++.h>
// https://www.acmicpc.net/blog/view/106
#define X first
#define Y second
#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
using namespace std;
// using namespace __gnu_pbds;
typedef long long ll;

// Define the ordered set using Policy-Based Data Structures
template<typename T>
using ordered_set = set<T>;
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int debugCnt;

ll solve() {
    ll ret = 0LL;
    // input
    int n, nq; cin >> n >> nq;
    vector<ll> W(n), Q(nq);
    ordered_set<int> setW;
    for(int i=0;i<n;++i) {
        cin >> W[i];
        setW.insert(i);
    }
    for(int i=0;i<nq;++i) cin >> Q[i];
    // preprocessing
    /// W preprocessing
    vector<ll> sortW = W; sort(ALL(sortW));
    vector<ll> coordW = sortW; coordW.erase(unique(ALL(coordW)), END(coordW));
    cout << "sortW.size(): " << sortW.size() << '\n';
    vector<ll> sum(coordW.size()+1); // sum[i]: Kinda like the sum from 1 to coordW[i-1] in sortW (or in W)
        ll prev=0LL;
        for(int i=0,e=coordW.size();i<e;++i) {
            sum[i+1] = sum[i] + (n-(lower_bound(ALL(sortW), coordW[i])-sortW.begin()))*(coordW[i]-prev);
            prev = coordW[i];
        }
    debugCnt=0;
    for(ll s : sum) {
        cout << "sum[" << debugCnt++ << "]: " << s << '\n';
    }
    vector<vector<int>> idxW(coordW.size());
        for(int i=0;i<n;++i) idxW[lower_bound(ALL(coordW), W[i])-coordW.begin()].push_back(i);
    
    debugCnt=0;
    for(const auto &sW: idxW) {
        cout << "idxW[" << debugCnt << "] (" << sW.size() << "):";
        for(int k: sW) {
            cout << '\t' << k;
        }
        cout << '\n';
    }
    /// Q preprocessing
    vector<ll> coordQ=Q; sort(ALL(coordQ)); coordQ.erase(unique(ALL(coordQ)), END(coordQ));
    vector<int> idxQ(nq); for(int i=0;i<nq;++i) idxQ[i] = lower_bound(ALL(coordQ), Q[i])-coordQ.begin();
    /// Ans initialization
    vector<ll> ans(coordQ.size());
    // queries
    int cycle = 0;
    for(int i=0,e=coordQ.size(),tmpc,j;i<e;++i) {
        ll x = coordQ[i]-1;
        tmpc = upper_bound(ALL(sum), x)-sum.begin()-1; // min: 0, max: coordW.size()-1
        if(cycle != tmpc) {
            for(j=cycle;j<tmpc;++j) for(int k: idxW[j]) setW.erase(k);
            cycle = tmpc;
        }
        // ans[i] = *setW.find_by_order((x-sum[cycle])%setW.size())+1;
        // From the set implementation
        auto it = setW.begin();
        advance(it, (x-sum[cycle])%setW.size());
        ans[i] = *it+1;
        cout << "ans [" << i << "] (" << coordQ[i] << "): " << ans[i] << '\n';
    }
    // return
    for(int i=0;i<nq;++i) {
        ret += ans[idxQ[i]];
        cout << "Query " << i << ": " << ans[idxQ[i]] << '\n';
    }
    return ret;
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
		/////////////////////////////////////////////////////////////////////////////////////////////
        
        
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << '\n';
		cout << solve() << '\n';
	}

    return 0;
}