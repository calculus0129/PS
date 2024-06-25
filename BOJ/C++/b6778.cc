#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    // TroyMartian, who has at least 3 antenna and at most 4 eyes;
    // VladSaturnian, who has at most 6 antenna and at least 2 eyes;
    // GraemeMercurian, who has at most 2 antenna and at most 3 eyes.
    int a, e;
    cin >> a; cin >> e;
    if(a>=3 && e<=4) cout << "TroyMartian\n";
    if(a<=6 && e>=2) cout << "VladSaturnian\n";
    if(a<=2 && e<=3) cout << "GraemeMercurian\n";

    return 0;
}