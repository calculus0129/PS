#include <bits/stdc++.h>
#define X first
#define Y second
#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

char s[101010], c[101010];
vector<int> ind;

void update() {
    for(int i=1,e=ind.size();i<e;++i) {
        s[ind[i]-1]=c[i-1];
    }
}

void work() {
    memset(s, 0, sizeof(s));
    memset(c, 0, sizeof(c));
    ind.clear();

    int m, n; scanf("%d %d", &n, &m);
    scanf("%s", s);

    ind.resize(m+1);
    for(int i=1;i<=m;++i) scanf("%d", &ind[i]);

    sort(ALL(ind));
    ind.erase(unique(ALL(ind)), END(ind));

    // printf("ind: ");
    // for(int i=1,e=ind.size();i<e;++i) {
    //     printf("%d ", ind[i]);
    // }
    scanf("%s", c);    
    sort(c, c+m);
    // printf("\nSorted c: %s\n", c);

    update();
    printf("%s\n", s);
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        work();
    }
    return 0;
}