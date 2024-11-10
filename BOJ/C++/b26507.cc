#include <bits/stdc++.h>
using namespace std;
struct chip {
    int grid[100];
    chip() {
        memset(grid, 0, 100*sizeof(int));
    }
    chip &operator+(const chip &other) const {
        chip* rp = new chip();
        chip& ret = *rp;
        for(int i=0;i<100;++i) rp->grid[i] = grid[i] + other.grid[i];
        return ret;
    }
    chip &operator+=(const chip &other) {
        for(int i=0;i<100;++i) grid[i] += other.grid[i];
        return *this;
    }
};

ostream &operator<<(ostream &os, const chip &c) {
    for(int i=0,j;i<10;++i) {
        for(j=0;j<10;++j) {
            os.width(2);
            os.fill('0');
            os << c.grid[10*i+j] << ' ';
        }
        os << '\n';
    }
    return os;
}

istream &operator>>(istream &is, chip &c) {
    // is.ignore();
    char buf[11];
    for(int i=0,j;i<10;++i) {
        is >> buf;
        for(j=0;j<10;++j) {
            c.grid[10*i+j] = buf[j]-'0';
        }
    }
    return is;
}

int main (){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<chip> arr(n);
    for(int i=0;i<n;++i) cin >> arr[i];
    int m; cin >> m;
    vector<chip> ans(m);
    string inp;
    cin.ignore(); // necessary! Else, empty string before \n is read by the getline(cin, str&)
    for(int i=0;i<m;++i) {
        getline(cin, inp);
        stringstream ss(inp);
        int a;
        while(ss >> a) {
            ans[i] += arr[a];
        }
        cout << ans[i] << '\n';
    }


    return 0;
}