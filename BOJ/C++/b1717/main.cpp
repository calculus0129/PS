#include <bits/stdc++.h>
using namespace std;

// IDK actually if this is a linked list, though.
// It may be just a list, but let's ignore it for now.
class linked_list {
    linked_list* nxt;
    inline linked_list* head();
    vector<int>* p;
public:
    linked_list() : nxt(NULL), p(NULL) {}
    inline linked_list(vector<int>* p) : nxt(NULL), p(p) {}

    bool operator==(linked_list &);
    linked_list& operator+=(linked_list &);  //for unionization
    //friend ostream& operator<<(ostream &out, linked_list &ll);
};

inline linked_list* linked_list::head() {
    linked_list* m=this; // const before * makes the pointed value constant.
    while(m->nxt!=NULL) m = m->nxt;
    //if(nxt!=NULL) nxt = m;
    return m;
}

bool linked_list::operator==(linked_list &rhs) {
    return head() == rhs.head();
}

linked_list& linked_list::operator+=(linked_list &rhs) {
    linked_list *h1 = head(), *h2 = rhs.head();
    if(h1 == h2) return *this;
    vector<int>* &p1=h1->p, *&p2=h2->p, *res = new vector<int>(*p1);
    res->insert(res->end(), p2->begin(), p2->end());
    p1->erase(p1->begin(), p1->end());
    p2->erase(p2->begin(), p2->end());
    p1=p2=NULL;
    linked_list *nxt_head = new linked_list(res);
    h1->nxt = h2->nxt = nxt_head;

    return *this;
}

int main() {
    cin.tie(NULL);
    int n, m;
    int f, a, b;
    vector<linked_list> vec;
    enum input {
        UNION,  // 0
        EQUAL,  // 1
    };
    cin >> n >> m;
    vec.resize(n+1);

    for(int i=0;i<=n;++i) {
        vec[i]=linked_list(new vector<int>(1, i));
    }
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

/*
class myset {
    vector<int> *s;
public:
    myset(vector<int> *p) : s(p) {}
    myset& operator+=(myset &other); // for unionizing.
    bool operator==(myset const &other) const;
};

myset& myset::operator+=(myset &other) {
    if(s==other.s) return *this;
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
}*/
