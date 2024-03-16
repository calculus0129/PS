#include <bits/stdc++.h>
using namespace std;
map<string, double> score;
int main() {
    score["A+"]=4.3;
    score["A0"]=4.0;
    score["A-"]=3.7;
    score["B+"]=3.3;
    score["B0"]=3.0;
    score["B-"]=2.7;
    score["C+"]=2.3;
    score["C0"]=2.0;
    score["C-"]=1.7;
    score["D+"]=1.3;
    score["D0"]=1.0;
    score["D-"]=0.7;
    score["F"]=0.0;
    cin.tie(NULL)->sync_with_stdio(false);
    int t;
    double sum=0;
    string a, grade;
    int w, tot_w=0;
    cin >> t;
    while(t-->0) {
        cin >> a >> w >> grade;
        tot_w+=w;
        sum += w*score[grade];
    }
    cout << fixed << setprecision(2) << round(sum/tot_w*100)/100;
    return 0;
}