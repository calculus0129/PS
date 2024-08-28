#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
struct Seg2DSweep {
	struct Query {
		bool start;
		int x, s, e;
		bool operator<(const Query &q) const {
			return x == q.x ? start : x<q.x;
		}
	};
	const int SZ;
	vector<int> lseg, cseg;
	vector<Query> queries;
	Seg2DSweep(int q, int n=15) : SZ(1<<n) {
		lseg.assign(SZ<<1, 0);
		cseg.assign(SZ<<1, 0);
		queries.resize(q);
	}
	int handle(int s, int e, int node, const Query &q) {
		if(e<q.s || q.e<s) return 0;
		int dif = 0;
		if(q.s<=s && e<=q.e) {
			dif = ladd(q.start, node, s, e);
			// cout << "dif on " << dif << '\t' << "s,e: " << s << ',' << e << '\n';
		} else {
			int mid = s+e>>1;
			dif = handle(s, mid, node<<1, q) + handle(mid+1, e, node<<1|1, q);
			if(cseg[node]) dif = 0;
		}
		lseg[node]+=dif;
		return dif;
	}
	int ladd(bool start, int node, int s, int e) {
		int ret = 0;
		if(start) {
			if(!cseg[node]) {
				ret = (e-s+1)-lseg[node];
			}
			cseg[node]++;
		} else if(cseg[node]) {
			if(--cseg[node] == 0) {
				ret = (node&SZ?0:lseg[node<<1] + lseg[node<<1|1]) - (e-s+1);
			}
		}
		return ret;
	}
	int solve(){
		sort(ALL(queries));
		int px=0, ans=0, len=0;
		for(const Query &q: queries) {
			ans += (q.x-px)*len;
			// cout << "add " << (q.x-px) << '*' << len << "=" << (q.x-px)*len << '\n';
			// cout << "handling query: " << q.start << ' ' << q.x << ' ' << q.s << ' ' << q.e << '\n';
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
		cin >> x1 >> y1 >> x2 >> y2;
		sweep.queries[i<<1] = {true, x1, y1, y2-1};
		sweep.queries[i<<1|1] = {false, x2, y1, y2-1};
	}
	cout << sweep.solve();
	return 0;
}
