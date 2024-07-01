/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <bits/stdc++.h>

using namespace std;

int Answer, n;

int arr[505050];
vector<bool> brr;
unordered_set<vector<bool>> s;

typedef long long ll;

bool input() {
    s.clear();
    memset(arr, 0, sizeof(arr));
    cin >> n;
    brr=vector<bool>(n, false);

    ll sum=0;

    for(int i=0, a;i<n;++i) {
        cin >> a;
        arr[i] = a;
        sum += a;
    }
    return sum<n;
}

void preprocess() {
    for(int i=n-1,s=0;i>=0;--i) {
        s += arr[i];
        if(s>0) {
            s--;
            brr[i]=true;
        }
    }
}

void work() {
    for(int i=0;i<n;++i) {
        brr.push_back(brr.front());
        brr.erase(brr.begin());
        s.insert(brr);
    }
    Answer=s.size();
}

int main(int argc, char** argv)
{
    setbuf(stdout, NULL);
    cin.tie(NULL); ios_base::sync_with_stdio(false);
	int T, test_case;
    s.rehash(500001);
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

		Answer = 1;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
        if(input()) {
            preprocess();
            work();
        }
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}