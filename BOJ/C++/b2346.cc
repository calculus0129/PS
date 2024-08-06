#include <bits/stdc++.h>
using namespace std;

class CircBuffer {
	public:
	const int cap;
	int n, idx;
	vector<int> arr;
	CircBuffer(int n)
	: cap(n), n(n), idx{1}, arr(n+1) {}
	int pop() {
		int tmp = idx, mov=arr[idx];
		arr[idx] = 0; --n;
		if(!n) return tmp;
		// mov = (mov+n*cap)%n;
		int delta = mov<0?-1:1;
		while(mov) {
			idx = (cap+idx-1+delta)%cap+1;
			if(arr[idx]) mov -= delta;
		}
		return tmp;
	}
	bool empty() {
		return !n;
	}
};

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n; cin >> n;
	CircBuffer arr(n);
	for(int i=1;i<=n;++i) cin >> arr.arr[i];
	while(!arr.empty()) cout << arr.pop() << ' ';
	return 0;
}
