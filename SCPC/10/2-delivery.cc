/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll work(ll arr[], int n) {
    int len = n>>2;
    ll ret = 0LL;
    sort(arr, arr+n);

    for(int i=n-1;i>=n-len;--i) ret += arr[i];
    for(int i=0;i<len;++i) ret -= arr[i];
    return ret<<1;

    // vector<ll> small(arr.begin(), arr.begin()+len), large(arr.begin(), arr.begin()+len);
    
    // sort(ALL(small));
    // sort(ALL(large));
    // for(int i=len;i<n;++i) {
    //     ll v = arr[i];
    //     auto a = upper_bound(ALL(large), v), b = upper_bound(ALL(small), v);
    //     if(a != large.begin()) {
    //         a = 
    //     }
    // }
}

int main(int argc, char** argv)
{
	int T, test_case;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
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
    ll arr[301010]={0};
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
        for(int i=0;i<n;++i) cin >> arr[i];

		cout << "Case #" << test_case+1 << endl;
		cout << work(arr, n) << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}