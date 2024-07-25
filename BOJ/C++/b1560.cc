#include <bits/stdc++.h>
using namespace std;
int n;

struct bignum {
    string s;
    bignum(string s): s(s) {}
    bignum(int num) {
        s = "";
        while(num) {
            s = (char)(num%10+'0') + s;
            num/=10;
        }
    }
    bignum add(const bignum &p) const {
        string ret = "";
        int l1 = s.size(), l2 = p.s.size();
        int len = max(l1, l2), mi = min(l1, l2);
        int tmp = 0;
        if(l1<l2) {
            ret = p.s;
            for(int i=1;i<=mi;++i) {
                tmp += (s[l1-i]-'0') + (p.s[l2-i]-'0');
                ret[len-i] = '0' + tmp%10;
                tmp/=10;
            }
            for(int i=mi+1;i<=len;++i) {
                tmp += ret[len-i]-'0';
                ret[len-i] = '0' + tmp%10;
                tmp/=10;
            }
            while(tmp) {
                ret = (char)('0'+tmp%10) + ret;
                tmp/=10;
            }
        } else {
            ret = s;
            for(int i=1;i<=mi;++i) {
                tmp += (s[l1-i]-'0') + (p.s[l2-i]-'0');
                ret[len-i] = '0' + tmp%10;
                tmp/=10;
            }
            for(int i=mi+1;i<=len;++i) {
                tmp += ret[len-i]-'0';
                ret[len-i] = '0' + tmp%10;
                tmp/=10;
            }
            while(tmp) {
                ret = (char)('0'+tmp%10) + ret;
                tmp/=10;
            }
        }
        // cout << ret << '\n';
        return bignum(ret);
    }
    // assume *this > p
    bignum sub(const bignum &p) const {
        string ret = "";
        int l1 = s.size(), l2 = p.s.size();
        assert(l1>=l2);
        int len = max(l1, l2), mi = min(l1, l2);
        int tmp = 0;
        bool debt = false;

        ret = s;
        for(int i=1;i<=mi;++i) {
            tmp = (s[l1-i]-'0') - (p.s[l2-i]-'0') - (debt?1:0);
            if(tmp<0) {
                tmp+=10;
                debt = true;
            } else debt = false;
            ret[len-i] = '0' + tmp%10;
            tmp = 0;
        }
        int nerim = mi+1;
        if(debt) {
            while(s[len-nerim] == '0') ++nerim;
            assert(nerim<=len);
            for(int i=mi+1;i<nerim;++i) ret[len-i] = '9';
            ret[len-nerim]--;
            // if(ret[len-nerim] == '0') ret = ret.substr(1);
        }
        size_t startpos = ret.find_first_not_of('0');
        if (startpos != string::npos) {
            ret = ret.substr(startpos);
        } else {
            ret = "0";
        }
        // cout << ret << '\n';
        return bignum(ret);
    }

};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    if(s == "1" || s == "2") {
        cout << s;
    } else {
        bignum S(s), two(2);
        cout << (S.add(S).sub(two)).s;
    }

    // string a, b;
    // cin >> a >> b;
    // bignum A(a), B(b);
    // cout << "A: " << A.s << "\nB: " << B.s << '\n';
    // cout << "A+B: " << A.add(b).s << '\n';
    // cout << "A-B: " << A.sub(b).s << '\n';


    return 0;
}