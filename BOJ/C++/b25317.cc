#include <bits/stdc++.h>
#define SGN(x) ((x)==0?0:(x)<0?-1:1)
#define BEGIN(x) x.begin()
#define ALL(x) BEGIN(x), x.end()
using namespace std;
const int SZ = 1<<18;
bool T[SZ<<1], L[SZ<<1];
typedef long long ll;
typedef long double ld;
set<ll> zeros;
vector<ll> sgns, coords;
int k=1;

void update_lazy(int node) {
    if(!L[node]) return;
    L[node] = false;
    if(node<SZ) {
        // no need to update the T[node] here right now.
        L[node<<1]^=true;
        L[node<<1|1]^=true;
    } else {
        T[node]=!T[node];
    }
}

void modify_interval(int l, int r, int node=1, int s=0, int e=SZ-1) {
    update_lazy(node);
    if(r<s || e<l) return;
    if(l<=s && e<=r) {
        L[node] = true;
        update_lazy(node);
        return;
    }
    int mid = s+e>>1;
    modify_interval(l, r, node<<1, s, mid);
    modify_interval(l, r, node<<1|1, mid+1, e);
    T[node] = T[node<<1] ^ T[node<<1|1];
}

bool sum(int l, int r, int node=1, int s=0, int e=SZ-1) {
    update_lazy(node);
    if(r<s || e<l) return false;
    if(l<=s && e<=r) return T[node];
    int mid = s+e>>1;
    return sum(l, r, node<<1, s, mid)^sum(l, r, node<<1|1, mid+1, e);
}

void insert(ll a, ll b) {
    if(a!=0LL) {
        ll q = floor(-b/(ld)a);
        // if(b%a == 0) {
        //     zeros.insert(-b/a);
        // }
        sgns.push_back(q);
    }
}

void post_insert(ll a, ll b) {
    k*=(a==0LL?SGN(b):SGN(a)); //cout << "k = k * " << (a==0LL?SGN(b):SGN(a)) << " == " << k << '\n';
    if(a!=0LL) {
        ll q = floor(-b/(ld)a);
        if(b%a == 0) {
            zeros.insert(-b/a);
        }
        modify_interval(0, lower_bound(ALL(coords), q)-BEGIN(coords));
    }
}

int query(ll c) {
    if(k==0 || zeros.find(c) != zeros.end()) return 0;
    int idx = lower_bound(ALL(coords), c)-BEGIN(coords);
    // cout << "num: " << idx << '\n';
    bool isnegative = k<0 ^ sum(idx, idx);
    return isnegative?-1:1;
}

bool isadd[200020];
ll arr[200020], brr[200020];

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    sgns.reserve(200020);
    coords.reserve(200020);
    vector<ll> queries;
    queries.reserve(200020);
    int q; cin >> q;
    ll a, b, c;
    for(int i=0,m,j=0;i<q;++i) {
        cin >> m;
        if(m == 1) {
            isadd[i] = true;
            cin >> a >> b;
            insert(a, b);
            arr[j]=a;
            brr[j++]=b;
        } else {
            cin >> c;
            queries.push_back(c);
        }
    }
    coords = sgns;
    sort(coords.begin(), coords.end());
    coords.erase(unique(ALL(coords)), coords.end());
    for(int i=0,j=0,jj=0;i<q;++i) {
        if(isadd[i]) {
            post_insert(arr[j], brr[j]);
            j++;
        } else {
            a = query(queries[jj++]);
            cout << (a==0?'0':a<0?'-':'+') << '\n';
        }
    }

    return 0;
}