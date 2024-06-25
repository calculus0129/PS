#include <bits/stdc++.h>
using namespace std;
int x;
typedef pair<int, double> pyo;
char staffname[10];
vector<pyo> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, N;
    cin >> X >> N;

    vector<pair<char, int>> parties;
    char partyId;
    int votes;

    // Read party votes and filter based on the 5% rule
    for (int i = 0; i < N; i++) {
        cin >> partyId >> votes;
        if (20 * votes >= X) {
            parties.push_back({partyId, votes});
        }
    }

    // This will store all scores with corresponding partyId
    vector<pair<double, char>> scores;

    // Generate scores for D'Hondt method
    // for (auto &p : parties) {
    //     for (int i = 1; i <= 14; i++) {
    //         scores.emplace_back((double)p.second / i, p.first);
    //     }
    // }
    for (auto &p : parties) {
        int scaled_votes = p.second * 14;
        for (int i = 1; i <= 14; i++) {
           scores.emplace_back(scaled_votes / i, p.first);
        }
    }

    // Sort scores in descending order to pick representatives
    sort(scores.rbegin(), scores.rend());

    // Count the representatives for each party
    map<char, int> representatives;
    for (int i = 0; i < 14; i++) {
        representatives[scores[i].second]++;
    }

    // Output results sorted by party identifier
    for (auto &rep : representatives) {
        cout << rep.first << ' ' << rep.second << '\n';
    }

    return 0;
}

// void add(int idx, int a) {
//     if(arr.size()==0) {
//         for(int i=14;i>=1;--i) arr.push_back({idx, a/(double)i});
//     }
//     else {
//         pyo tmp = {idx, 0};
//         for(int i=1;i<=14;++i) {
//             tmp.second = a/(double)i;

//             if(lower_bound(arr.begin(), arr.end(), tmp, [](const pyo &a, const pyo &b) -> bool {
//                 return a.second < b.second;
//             }) == arr.begin()
//             && arr[0].second > tmp.second)
//             {
//                 break;
//             }

//             arr.insert(lower_bound(arr.begin(), arr.end(), tmp, [](const pyo &a, const pyo &b) -> bool {
//                 return a.second < b.second;
//             }), tmp);
//             arr.resize(14);
//         }
//     }
// }

// int main() {
//     cin.tie(NULL); ios_base::sync_with_stdio(false);
//     cin >> x;
//     int n, a;
//     cin >> n;
//     for(int i=0;i<n;++i) {
//         cin >> staffname[i] >> a;
//         if(a>=0.05*x) {
//             add(i, a);
//         }
//     }
//     char c;
//     map<char, int> chips;
//     for(const pyo &tmp : arr) {
//         c = staffname[tmp.first];
//         if(chips.find(c) == chips.end()) {
//             chips[c] = 1;
//         }
//         else {
//             chips[c] += 1;
//         }
//     }
//     for(auto p: chips) {
//         cout << p.first << ' ' << p.second << '\n';
//     }

//     return 0;
// }