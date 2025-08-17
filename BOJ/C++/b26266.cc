#include <bits/stdc++.h>
#define MINUS(a,b) ((a)-(b)+26)%26
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    char plain[200001]="", crypt[200001]="", K[200001]="";
    cin >> plain >> crypt;
    int n = strlen(plain);
    for(int i=0;i<n;++i) {
        K[i]=MINUS(crypt[i], plain[i]+1)+'A';
    }
    int l = n;
    bool r;
    for(int i=1,j;i<=(n>>1);++i) if(n%i == 0) {
        r = true;
        for(j=i;j<n && r;++j) r = K[j] == K[j%i];
        if(r) {
            l = i;
            break;
        }
    }
    K[l]='\0';
    cout << K;
    return 0;
}