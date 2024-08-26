#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
struct Seg2DSweep {
	struct Query {
		bool start;
		int x, s, e;
		bool operator<(const Query &q) const {
			return x == q.x ? start > q.start : x<q.x;
		}
	};
	const int SZ;
	vector<int> lseg, cseg;
	vector<Query> queries;
	Seg2DSweep(int q, int n=15) : SZ(1<<n) {
		lseg.resize(SZ<<1);
		cseg.resize(SZ<<1);
		queries.resize(q);
	}
	int handle(int s, int e, int node, const Query &q) {
		if(e<q.s || q.e<s) return 0;
		int dif = 0;
		if(s<=q.s && q.e<=e) {
			dif = ladd(q.start, node, s, e);
		} else {
			int mid = s+e>>1;
			dif = handle(s, mid, node<<1, q) + handle(mid+1, e, node<<1|1, q);
		}
		lseg[node]+=dif;
		return dif;
	}
	int ladd(bool start, int node, int s, int e) {
		int ret = 0;
		if(start) {
			if(!cseg[node]) {
				ret = e-s-lseg[node];
			}
			cseg[node]++;
		} else if(cseg[node]) {
			cseg[node]--;
			if(cseg[node] == 0) ret = lseg[node<<1] + lseg[node<<1|1] - (e-s);
		}
		lseg[node]+=ret;
		return ret;
	}
	int solve() {
		sort(ALL(queries));
		int px=0, ans=0, len=0;
		for(const Query &q: queries) {
			ans += (q.x-px)*len;
			len += handle(0, SZ-1, 1, q);
			px=q.x;
		}
		return ans;
	}
};

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int q; cin >> q;
	Seg2DSweep sweep(q<<1);
	for(int i=0,x1,x2,y1,y2;i<q;++i) {
		cin >> x1 >> x2 >> y1 >> y2;
		sweep.queries[i<<1] = {true, x1, y1, y2};
		sweep.queries[i<<1|1] = {false, x2, y1, y2};
	}
	cout << sweep.solve();
	return 0;
}
