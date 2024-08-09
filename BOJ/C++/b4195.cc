#include <bits/stdc++.h>
using namespace std;
int n;
unordered_map<string, int> mp;
int S[101010<<1], Rank[101010<<1], Size[101010<<1];
void init() {
	memset(S, 0, sizeof(S));
	memset(Rank, 0, sizeof(Rank));
	memset(Size, 0, sizeof(Size));
	n=0;
	mp.clear();
}
int add(const string &s)
{
	if(mp.find(s) == mp.end()) {
		mp[s] = S[n] = n;
		Size[n] = 1;
		//Rank[n] = 0;
		++n;
	}
	return mp[s];
}
int find(int a) {
	if(S[a] == a) return a;
	//Rank[a] = 1;
	return S[a] = find(S[a]);
}
bool merge(int a, int b) {
	a = find(a), b = find(b);
	if(a == b) return true;
	if(Rank[a] > Rank[b]) swap(a, b);
	S[a] = b;
	Size[b] += Size[a];
	if(Rank[a] == Rank[b]) Rank[b]++;
	return false;
}

int main() {
	mp.rehash(101010<<1);
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int T, f, a, b; cin >> T;
	string s1, s2;
	while(T--) {
		init();
		cin >> f;
		while(f--) {
			cin >> s1 >> s2;
			a = add(s1);
			b = add(s2);
			merge(a, b);
			cout << Size[find(a)] << '\n';
		}
	}

	return 0;
}
