#include <bits/stdc++.h>
using namespace std;

class myset {
    vector<int> *s;
public:
    myset(vector<int> *p) : s(p) {}
    myset& operator+=(myset &other); // for unionizing.
    bool operator==(myset const &other) const;
};

myset& myset::operator+=(myset &other) {
    //if(s==other.s) return *this;
    if(s->begin()==s.other->begin()) return *this;
    s->insert(s->end(), other.s->begin(), other.s->end());
    delete other.s;
    other.s = s;
    return *this;
}

bool myset::operator==(myset const &other) const {
    return s == other.s;
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<myset> vec;
    for(int i=0;i<=n;++i) {
        vec.push_back(myset(new vector<int>(1, i)));
    }
    enum input {
        UNION,  // 0
        EQUAL,  // 1
    };
    int f, a, b;
    while(m--) {
        cin >> f >> a >> b;
        switch(f) {
        case UNION:
            vec[a]+=vec[b];
            break;
        case EQUAL:
            puts(vec[a]==vec[b]?"YES":"NO");
        }
    }
    return 0;
}
