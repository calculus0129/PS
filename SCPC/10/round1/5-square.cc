// Got 128/400

#include <bits/stdc++.h>
const int MAX=1000000000;
const int SQRT_MX=31622;
const int SQRT_SQRT_MX=177;
using namespace std;

int sumFloors(int n, int k) {
    int ret = 0;
    while(n/=k) ret += n;
    return ret;
}

int work(map<int, int> & freq) {
    int ret=0;
    vector<int> small(SQRT_MX+1);
    for(const auto &[num, f]: freq) {
        if(num>SQRT_MX) break;
        small[num]=f;
    }
    for(int i=1;i<=SQRT_MX;++i) if(small[i]) {
        freq.erase(freq.find(i));
    }
    for(int i=2, a;i<=SQRT_SQRT_MX;++i) if(small[i]>=i) {
        a = small[i]/i;
        ret += a;
        small[i*i] += a;
    }
    for(int i=SQRT_SQRT_MX+1, a;i<=SQRT_MX;++i) if(small[i]>=i) {
        a = small[i]/i;
        ret += a;
        freq[i*i]+=a;
    }
    for(const auto &[num, f]: freq) if(f>1) {
        ret += sumFloors(f, num);
    }
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T, n, q, l, r;
    cin >> T;
    map<int, int> frequency;
    // frequency.rehash(50016);
    for (int t = 1; t <= T; t++) {
        cin >> n;
        vector<int> a(n);
        for (int &num : a) {
            cin >> num;
        }

        cin >> q;
        cout << "Case #" << t << endl;
        while (q--) {
            frequency.clear();
            cin >> l >> r;
            l--; r--;  // Convert to 0-based index

            // Count occurrences of each number in the range [l, r]
            for (int i = l; i <= r; i++) {
                frequency[a[i]]++;
            }
            // for(const auto &[num, cnt]: frequency) {
            //     cout << num << ": " << cnt << '\n';
            // }

            cout << work(frequency) << endl;
        }
    }
    return 0;
}