#include <bits/stdc++.h>
using namespace std;
int status = 0; // 666이 나오는 가능한 가장 큰 첫 자릿수. (e.g. ans=1666 => 0, ans=6666 => 1, ans=16660 => 1)
int l = 3; // 자릿수. e.g. 666 => 3. 6661 => 4. 12316662 => 8.
int ans = 666; // 답.

int pow10(int exp) {
    int ret = 1;
    while(exp--) ret *= 10;
    return ret;
}

/*void updatestatus() {
    int i=l-3;
    while(i>status) if(ans/pow10(i)%1000 == 666) {
        status = i;
        break;
    }
}*/

void next() {
    if((ans+1) % pow10(status) != 0) ++ans; // 이건 *66699...9보다 약간 작은 case. e.g. 6669997 -> 6669998
    else if(status>=3) { // *666999(...9)꼴 (9가 3개 이상일 때)
        status = 0;
        ans += 667; // *667(0...)666을 반환.
    }
    else if(status == 2) { // *66699 -> *67666 (9가 2개일 때)
        status = 0;
        ans += 967;
    }
    else if(status == 1) { // *6669 -> *7666
        status = 0;
        ans += 997;
    }
    else { // *666꼴
        if(ans%1000000 == 665666) { // *665666 -> *666000
            ans += 334;
            status = 3;
        }
        else if(ans%100000 == 65666) { // *65666 -> *66600
            ans += 934;
            status = 2;
        }
        else if(ans%10000 == 5666) { // *5666 -> *6660
            ans += 994;
            status = 1;
        }
        else { // *[^5]666
            ans += 1000; // ans는 일단 이렇게 리턴하면 됨.
            //updatestatus();
            if(ans>pow10(l)) { // (99...9)666 -> 1(00...0)666 시 자릿수 1 증가.
                ++l;
            }
        }
    }
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while(--n>0) next();
    cout << ans;
    return 0;
}