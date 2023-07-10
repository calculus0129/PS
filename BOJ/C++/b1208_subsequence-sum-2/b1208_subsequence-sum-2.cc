#include <bits/stdc++.h>
using namespace std;
//const size_t SIZE=2*1e6;
int s, n, arr[41]; //arr1[2*SIZE+1], arr2[2*SIZE+1], arr[41], s, n;
map<int,int> mp;
size_t ans;

// add all the ones with DFS. We can even map negative integers!
void left(int idx, int sum) {
    if(idx == n/2) {
        mp[sum]++; return;
    }
    left(idx+1, sum);
    left(idx+1, sum+arr[idx]);
}

void right(int idx, int sum) {
    if(idx == n) {
        ans += mp[s-sum];
        return;
    }
    right(idx+1, sum);
    right(idx+1, sum+arr[idx]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int i=-1;
    cin >> n >> s;
    while(++i<n) cin >> arr[i];
    left(0, 0);
    right(n>>1, 0);
    if(s==0) --ans;
    cout << ans;

    return 0;
}

/*void make_arr(int start, int end) {
    multiset<int> s, tmp;
    s.insert(SIZE+0);
    int i, j, e;
    for(i=start,e=end;i<e;++i) {
        for(const auto &m: s) {
            tmp.insert(m);
            tmp.insert(m+arr[i]);
        }
        swap(s, tmp);
        tmp.erase(tmp.begin(), tmp.end());
    }
    //s.erase(s.find(0));
    for(auto const &i:s) arr2[i]=s.count(i);
}*/ // swapping, ordering, and etc. gave more time complexity than expected.