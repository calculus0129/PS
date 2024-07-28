/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <bits/stdc++.h>
using namespace std;

int work(const string &str, char delimiter) {
    int ret=0, last=0;
    string token;
    stringstream ss(str);
    getline(ss, token, delimiter);
    bool r = false;
    while(getline(ss, token, delimiter)) {
        ret += max(0, 2-(last=(int)token.size()));
        r = true;
        // cout << token.size() << ' ';
    }
    if(r && str.back() == 'B') {
        ret -= max(0, 2-last);
    }
    // cout << endl;
    return ret;
}

int main(int argc, char** argv)
{
	int T, test_case;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string s;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		// Print the answer to standard output(screen).
        int n;
        cin >> n;
        cin >> s;
        // vector<int> tmp = parse(s, 'A');

		cout << "Case #" << test_case+1 << endl;
		// for(int i: tmp) cout << i << ' ';
        cout << work(s, 'A') << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}