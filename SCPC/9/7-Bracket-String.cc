#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll ans;
int n;
vector<string> tokens;
vector<pii> stk;

bool Open(char c) { return c == '(' || c == '{'; }
bool Match(char a, char b) { return a == '(' && b == ')' || a == '{' && b == '}';}

void printTokens() {
    cout << "tokens: ";
    for(auto p: tokens)
        cout << p << ' ';
    cout << '\n';
}

void input() {
    string s;
    // cin.ignore();
    cin >> n;
    // cin.ignore();
    cin >> s;
    vector<int> idx(n, -1), cstk;
    for(int i=0;i<n;++i) {
        if(Open(s[i])) {
            cstk.push_back(i);
        } else {
            if(!cstk.empty() && Match(s[cstk.back()], s[i])) {
                idx[cstk.back()] = i;
                idx[i] = cstk.back();
                cstk.pop_back();
            } else {
                cstk.clear();
            }
        }
    }
    for(int i=0,j=0;i<n;i=j) {
        if(idx[i] == -1) {j++; continue;}
        while(j<n && idx[j]!=-1) ++j;
        tokens.push_back(s.substr(i, j));
    }
}

ll nums(const string &s) {
    ll ret = 0LL;
    vector<ll> val{0};
    for(auto c: s) {
        if(Open(c)) {
            val.push_back(0);
        }
        else {
            ret += val.back()*(val.back()+1)>>1;
            val.pop_back(); val.back() += 1;
        }
    }
    ret += val.back()*(val.back()+1)>>1;

    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		ans = 0LL;
		/////////////////////////////////////////////////////////////////////////////////////////////
        input();
        // printTokens();
        for(const string &i: tokens) ans += nums(i);
        tokens.clear();
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << '\n';
		cout << ans << '\n';
	}

    return 0;
}