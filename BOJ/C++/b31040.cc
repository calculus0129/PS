#include <bits/stdc++.h>
using namespace std;
bool mp[5][5];

int arr[][2] = {
    {1,-2},
    {2,-1},
    {2,1},
    {1,2}
};

bool validness() {
    bool valid;
    int cnt = 0;
    for(int i=0,j;i<5;++i) for(j=0;j<5;++j) cnt += mp[i][j];
    valid = cnt == 9;
    for(int i=0,j,k,nx,ny;valid && i<3;++i) for(j=0;valid && j<5;++j) if(mp[i][j]) for(k=0;valid && k<4;++k) {
        nx = i + arr[k][0];
        ny = j + arr[k][1];
        valid = (nx>4 || ny>4 || ny<0 || !mp[nx][ny]);
    }
    return valid;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        cin.ignore(); // ignore a line. nyum.
        for(int i=0,j;i<5;++i) {
            string s; getline(cin, s);//cout << s.size() << '\n';
            for(j=0;j<5;++j) mp[i][j] = s[j] == 'k';
        }
        cout << (validness()?"valid":"invalid") << '\n';
    }

    return 0;
}