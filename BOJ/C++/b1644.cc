#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
int ans;
bool sieve[4000001];

void cross(int p) {
    primes.push_back(p);
    int comp = p<<1;
    while(comp<=4000000) {
        sieve[comp] = false;
        comp+=p;
    }
}

void init() {
    memset(sieve, 1, sizeof(sieve));
    cross(2);
    for(int i=3;i<=4000000;i+=2) if(sieve[i]) cross(i);
}

void two_pointer(int n) {
    const auto e = primes.end();
    auto i = primes.begin(), j = primes.begin();
    int sum = 0;
    while(i!=e) {
        if(sum<n) {
            if(j == e) break;
            sum += *j++;
            // cout << sum << endl;
        }
        else {
            if(sum == n) ++ans;
            sum -= *i++;
            // cout << sum << endl;
        }
    }
}

int main() {
    init();
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    two_pointer(n);
    cout << ans;

    return 0;
}