#include <bits/stdc++.h>
using namespace std;

int n;
string Q[1000], A[1000];
vector<int> fQ[1000];
struct info {
    pair<int,int> cmp;
    int index;
    bool operator<(const info &other) const {
        return cmp < other.cmp;
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int m;

    cin >> n >> m;
    for(int i=0,j,k;i<n;++i) {
        cin >> Q[i] >> A[i];
        fQ[i].resize(Q[i].size(), 0);
        for(j=1,k=0;j<Q[i].size();++j) {
            while(k > 0 && Q[i][j] != Q[i][k]) k = fQ[i][k-1];
            if(Q[i][j] == Q[i][k]) fQ[i][j] = ++k;
        }
    }
    string S;
    vector<info> indices;
    indices.reserve(5000);
    while(m--) {
        cin >> S;
        for(int k=0,i,j;k<n;++k) {
            for(i=0,j=0;i<S.size();++i) {
                while(j>0 && S[i]!=Q[k][j]) j = fQ[k][j-1];
                if(S[i] == Q[k][j]) ++j;
                if(j == Q[k].size()) {
                    indices.push_back(info({make_pair(i-j+1, i), k}));
                    j = fQ[k][j-1];
                }
            }
        }
        sort(indices.begin(), indices.end());
        if(indices.size() == 0) {
            cout << -1;
        } else for(auto i=indices.begin(), e = indices.end();i!=e;++i) {
            cout << A[i->index];
        }
        cout << '\n';
        indices.clear();
    }
    return 0;
}