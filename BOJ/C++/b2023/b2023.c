#include <stdio.h>
size_t n;
unsigned int primes[1229];
int isprime(unsigned int p) {
    size_t i=0;
    while(i<n && primes[i]*primes[i]<=p) if(p % primes[i++]==0) return 0;
    return 1;
}

int main() {
    primes[n++]=2;
    int r;
    unsigned int i,x, weird_primes[9][16]={{},{2, 3, 5, 7}};
    size_t m,j, sizes[9]={0,4,};
    for(i=3;i<10001;i+=2) if(isprime(i)) primes[n++]=i;
    for(j=2;j<=8;++j) for(m=0;m<sizes[j-1];++m) for(i=1;i<10;i+=2) if(isprime(x = weird_primes[j-1][m]*10+i)) weird_primes[j][sizes[j]++]=x;
    //for(m=1;m<=8;++m) printf("%u ", sizes[m]); // 4 9 14 16 15 12 8 5 
    scanf("%u", &m);
    for(j=0;j<sizes[m];++j) {
        printf("%u\n", weird_primes[m][j]);
    }
    
    return 0;
}