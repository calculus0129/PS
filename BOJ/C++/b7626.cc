#include <bits/stdc++.h>
#define X first
#define Y second
#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
// https://byeo.tistory.com/entry/boj-7626-%EC%A7%81%EC%82%AC%EA%B0%81%ED%98%95
// 하위 호환 문제: b3392

struct Seg2DSweep {
	struct Query {
		bool start;
		int x, s, e;
		bool operator<(const Query &q) const {
			return x == q.x ? start : x<q.x;
		}
	};
	const int SZ;
	vector<int> lseg, cseg, ycoords;
	vector<Query> queries;
	Seg2DSweep(int n=19) : SZ(1<<n) {
		lseg.assign(SZ<<1, 0);
		cseg.assign(SZ<<1, 0);
		ycoords.clear(); // ESSENTIAL!!!
		queries.clear(); // ESSENTIAL!!!
	}
	void addRect(int x1, int x2, int y1, int y2) {
		ycoords.push_back(y1);
		ycoords.push_back(y2);
		queries.push_back({true, x1, y1, y2});
		queries.push_back({false, x2, y1, y2});
	}

	int ladd(bool start, int node, int s, int e) {
		int ret = 0;
		cout << node << endl;
		if(start && !cseg[node]++) {
			ret = (ycoords[e+1]-ycoords[s])-lseg[node];
		} else if(!start && cseg[node]--==1) {
			ret = (node&SZ?0:lseg[node<<1]+lseg[node<<1|1])-(ycoords[e+1]-ycoords[s]);
		}
		return ret;
	}

	int handle(int node, int s, int e, const Query &q) {
		if(e<q.s || q.e<s) return 0;
		int dif = 0;
		if(q.s<=s && e<=q.e) {
			dif = ladd(q.start, node, s, e);
		} else {
			int mid = s+e>>1;
			dif = handle(node<<1, s, mid, q) + handle(node<<1|1, mid+1, e, q);
			if(cseg[node]) dif = 0;
		}
		lseg[node] += dif;
		return dif;
	}

	ll solve() {
		ll ret = 0LL;
		sort(ALL(ycoords)); ycoords.erase(unique(ALL(ycoords)), END(ycoords));
		for(Query &q: queries) {
			q.s = lower_bound(ALL(ycoords), q.s)-BEGIN(ycoords);
			q.e = lower_bound(ALL(ycoords), q.e)-BEGIN(ycoords)-1;
		}
		sort(ALL(queries));
		int px=0, len=0;
		for(const Query &q: queries) {
			ret += (ll)(q.x-px)*len;
			len += handle(1, 0, SZ-1, q);
			px = q.x;
		}
		return ret;
	}
};


int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	Seg2DSweep sweep;
	int n; cin >> n;
	while(n--) {
		int x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
		sweep.addRect(x1, x2, y1, y2);
	}
	cout << sweep.solve();
	return 0;
}
