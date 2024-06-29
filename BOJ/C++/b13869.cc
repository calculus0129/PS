#include <bits/stdc++.h>
using namespace std;
int n;
double s[101010], ans;
deque<int> deq;

double area(int i1, int i2) {
    return 0.5*s[i1]*s[i2]*sin(2*M_PI/n); // 1/2*s[i1]*s[i2]*sin(2*M_PI/n); => 1/2먼저 0으로 계산됨..ㅋㅋㅋ
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;++i) {
        cin >> s[i];
    }
    sort(s, s+n, [](double a, double b) -> bool {
        return a>b;
    });
    deq.push_back(0);
    for(int i=1;i<n;++i) {
        if(i&1) deq.push_front(i);
        else deq.push_back(i);
    }
    ans += area(deq.front(),deq.back());
    int a = deq.front();
    deq.pop_front();
    while(!deq.empty()) {
        ans += area(a, deq.front());
        a = deq.front();
        deq.pop_front();
    }
    cout << fixed << setprecision(3) << showpoint << ans;

    return 0;
}