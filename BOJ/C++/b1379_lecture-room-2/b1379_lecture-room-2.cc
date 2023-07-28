#include <bits/stdc++.h>
using namespace std;

struct lecture {
    int num, start, end;
    bool operator<(const lecture &rhs) const {
        return start<rhs.start;
    }
};

int n, nums[101010], s[101010], e[101010], ans[101010], k=1;
lecture L[101010];
vector<pair<int,int>> vec(1, {0, 1});

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    return a.first>b.first;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    lecture tmp;
    cin >> n;
    for(int i=1;i<=n;++i) cin >> L[i].num >> L[i].start >> L[i].end;
    sort(L+1, L+n+1);
    for(int i=1;i<=n;++i) nums[i]=L[i].num, s[i]=L[i].start, e[i]=L[i].end;
    priority_queue<pair<int,int>, vector<pair<int,int>>, bool(*)(const pair<int,int> &, const pair<int,int> &)> pq(cmp);
    pq.push({e[1], 1});
    ans[nums[1]]=1;
    int x, y;
    for(int i=2;i<=n;++i) {
        x = pq.top().first, y = pq.top().second;
        if(x<=s[i]) {
            pq.pop();
            pq.push({e[i], ans[nums[i]]=y});
        } else {
            pq.push({e[i], ans[nums[i]]=++k});
        }
    }
    cout << k << '\n';
    for(int i=1;i<=n;++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}