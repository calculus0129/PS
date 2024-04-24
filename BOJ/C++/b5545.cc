#include <bits/stdc++.h>
using namespace std;
struct eff {
    int calorie, price;
    bool operator<(const eff & other) const {
        return calorie*other.price < price * other.calorie;
    }
};
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int a, b; cin >> a >> b;
    int c; cin >> c;
    eff pizza = {c, a};
    priority_queue<int> pq;
    for(int i=0, d;i<n;++i) {
        cin >> d;
        pq.push(d);
    }
    while(!pq.empty() && pizza<eff({pq.top(), b})) {
        pizza.calorie += pq.top();
        pizza.price += b;
        pq.pop();
    }
    cout << pizza.calorie/pizza.price;

    return 0;
}