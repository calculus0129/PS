#include <bits/stdc++.h>
using namespace std;

struct book {
    int count;
    string name;
    bool operator<(const book &other) const { // https://dpcks5959.tistory.com/81
        return count == other.count ? name.compare(other.name) < 0 : count > other.count;
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    map<string, int> sold;
    vector<book> arr;
    string s;
    arr.reserve(n);
    while(n--) {
        cin >> s;
        sold[s]++;
    }
    for(auto it = sold.begin(), e = sold.end();it!=e;it++) {
        arr.push_back({it->second, it->first});
    }
    cout << min_element(arr.begin(), arr.end())->name;
    

    return 0;
}