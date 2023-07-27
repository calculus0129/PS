#include <bits/stdc++.h>
using namespace std;

inline static int b362num(char c) {
    if(c<='9') return c-'0';
    return c-'A'+10;
}

inline static char num2b36(int a) {
    if(a<10) return '0'+a;
    return 'A'+a-10;
}

// 일의 자리 숫자 at index 0.
class b36 {
    public:
    vector<char> data;
    b36()
    : data(1, '0') {}
    b36(vector<char> data)
    : data(vector<char>(data.rbegin(), data.rend())) {}
    b36(string data)
    : data(vector<char>(data.rbegin(), data.rend())) {}
    b36 operator+(const b36 &) const;
    b36& operator+=(const b36 &);
    b36 operator*(int) const;
    bool operator==(const b36 &) const;
    bool operator!=(const b36 & other) const {
        return !(this->operator==(other));
    }
    bool operator<(const b36 &) const;
    string output() const;
    map<char, b36> search() const;
};

b36 b36::operator+(const b36 &other) const {
    b36 lhs = *this, rhs = other;
    size_t n = data.size();
    if(n<rhs.data.size()) {
        n = rhs.data.size();
        lhs.data.resize(n, '0');
    } else rhs.data.resize(n, '0');
    vector<char> rdata(n, '0');
    int cur=0;
    for(size_t i=0;i<n;++i) {
        cur += b362num(rhs.data[i]) + b362num(lhs.data[i]);
        rdata[n-1-i] = num2b36(cur%36);
        cur/=36;
    }
    if(cur==1) rdata.insert(rdata.begin(), '1');
    return b36(rdata);
}

b36& b36::operator+=(const b36 &other) {
    *this = *this + other;
    return *this;
}

/* Implement as looping addition
 * Since we cannot store arbitrarily large number.
 * This would be better than fast but limited multiplication.
 */ 
b36 b36::operator*(int x) const {
    b36 ret;
    while(x--) ret+=*this;
    return ret;
}

bool b36::operator==(const b36 &other) const {
    bool ret=data.size()==other.data.size();
    for(size_t i=0, e=data.size();i<e && ret;++i) if(data[i] != other.data[i]) ret=false;
    return ret;
}

bool b36::operator<(const b36 & other) const {
    if(data.size()!=other.data.size()) return data.size()<other.data.size();
    for(size_t i=data.size()-1, e=-1;i>e;--i) if(data[i] != other.data[i]) return data[i] < other.data[i];
    return false; // Doesn't matter in ordering.
}

string b36::output() const {
    string ret(data.rbegin(), data.rend());
    return ret;
}

map<char, b36> b36::search() const {
    map<char, b36> ret;
    string tmp="1";
    for(size_t i=0,e=data.size();i<e;++i) {
        ret[data[i]] += b36(tmp);
        tmp.push_back('0');
    }
    return ret;
}

void test() {
    assert(string(1, '1')=="1");
    b36 a("123"), b("123");
    assert(a==b);
    vector<b36> vec(1);
    assert(b36("0")==vec[0]);
    assert(b36("123")+b36("456") == b36("579"));
    assert(b36("ZZZ")+b36("1")==b36("1000"));
    assert(b36("1000").output() == "1000");
    a += b*34;
    assert(a==b36("110X"));
    auto mp = a.search();
    assert(mp['1']==b36("1100"));
    exit(0);
}

void test2() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //test();
    //test2();
    int n, i; cin >> n;
    vector<b36> arr;
    b36 res, a;
    string s;
    i=n;
    map<char, b36> mp, tmp;
    while(i--) {
        cin >> s;
        res += a=b36(s);
        tmp = a.search();
        for(const auto &[key, value]: tmp) {
            mp[key]+=value;
        }
    }
    for(const auto &[key, value]: mp) arr.push_back(value*(35-b362num(key)));
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    size_t k;
    cin >> k;
    if(k>arr.size()) k=arr.size();
    for(size_t i=0;i<k;++i) {
        res += arr[i];
    }
    cout << res.output();

    return 0;
}