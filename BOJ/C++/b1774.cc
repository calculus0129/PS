#include <bits/stdc++.h>
using namespace std;
int n, m, S[1010], Rank[1010];
int Find(int a) {
	if(S[a] == a) return a;
	return S[a] = Find(S[a]);
}

bool inSameSet(int a, int b) { return Find(a) == Find(b); }
bool merge(int a, int b) {
	a = Find(a), b = Find(b);
	if(a == b) return true;
	if(Rank[a]>Rank[b]) swap(a, b);
	S[a] = b;
	if(Rank[a] == Rank[b]) Rank[b]++;
	return false;
}

struct vec {
	int x, y;
	vec operator+(const vec &v) const {
		return vec({x+v.x, y+v.y});
	}
	vec operator-(const vec &v) const {
		return vec({x-v.x, y-v.y});
	}
	double magn() const {
		return sqrt(pow(x,2)+pow(y,2));
	}
};
double dist(const vec &a, const vec &b) {
	return (b-a).magn();
}

vec coords[1010];
double ans;

int main() 
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1;i<=n;++i) S[i] = i;
	for(int i=1;i<=n;++i) cin >> coords[i].x >> coords[i].y;
	int a, b; while(m--) {
		cin >> a >> b;
		merge(a, b);
	}
	auto cmp = [coords](const pair<int,int> &a, const pair<int,int> &b) {
		return dist(coords[a.first], coords[a.second]) > dist(coords[b.first], coords[b.second]);
	};

	priority_queue<pair<int,int>, vector<pair<int,int>>, bool(*)(const pair<int,int> &, const pair<int,int> &)> pq(cmp);
	for(int i=1, j;i<n;++i) for(j=i+1;j<=n;++j) if(!inSameSet(i, j)) pq.push({i, j});
	while(!pq.empty()) {
		auto [p, q] = pq.top(); pq.pop();
		if(!merge(p, q)) ans += dist(coords[p], coords[q]);
	}
	cout << fixed << setprecision(2) << ans;
	return 0;
}
