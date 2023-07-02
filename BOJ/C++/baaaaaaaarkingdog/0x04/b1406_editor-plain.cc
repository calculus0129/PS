#include <bits/stdc++.h>
using namespace std;

template <class T>
class ldnode {
    T dat;
    ldnode *pre, *nxt;

    ldnode* head() {
        ldnode* ret = this;
        while(ret->pre!=NULL) ret = ret->pre;
        return ret;
    }

    ldnode* tail() {
        ldnode *ret = this;
        while(ret->nxt!=NULL) ret = ret->nxt;
        return ret;
    }

    size_t size() {
        ldnode *h = head(), *t = tail();
        size_t ret = 1;
        while(h!=t) {
            ret++;
            h = h->nxt;
        }
        return ret;
    }

    public:

    void resize(size_t siz) {
        ldnode *h = head();
        
    }

    template <class E>
    ldnode(E arr) {
        ldnode *p=this;
        for(T &c: arr) {
            p->dat=c;
        }
    }
};

int main() {
    string s;
    cin >> s;
    ldnode<char> l;
    for(auto c:s) l.

    return 0;
}