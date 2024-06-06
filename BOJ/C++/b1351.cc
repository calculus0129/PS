#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli p, q;
map<lli, lli> mp;

void findTerm(lli n) {
    if(mp.find(n) != mp.end()) return;
    lli pt = n/p, qt=n/q;
    findTerm(pt);
    findTerm(qt);
    mp.insert({n, mp[pt]+mp[qt]});
}

int main() {
    lli n;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> p >> q;
    // Bottom-up DP would yield in prohibitively large amount of computations.
    // Top-Down approach is required.
    // Computing each value from A0, We would have to call N (<=10^12) times in the worst case.
    // Hence storing the value would greatly lower the cost.
    // (DP more efficient than Divide and Conquer here.)
    // The number of stored key-value pair entry will be no more than about 40*40.
    // because N <= 2^40
    mp.insert({0LL, 1});

    findTerm(n);
    cout << mp[n];

    return 0;
}