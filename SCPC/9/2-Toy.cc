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
unordered_set<size_t> s;

typedef long long ll;

const size_t BASE = 31;
const size_t MOD = 1e9 + 7;

// Compute the initial hash of the deque
size_t compute_hash(const vector<bool>& d) {
    size_t hash = 0;
    for (bool b : d) {
        hash = (hash * BASE + (b ? 1 : 0)) % MOD;
    }
    return hash;
}

// Update the hash for the deque after a rotation
size_t roll_hash(size_t current_hash, bool front, bool back, size_t base_power) {
    current_hash = (current_hash + (MOD - (front ? base_power : 0)) % MOD) % MOD; // Remove old front
    current_hash = ((current_hash * BASE) % MOD + (back ? 1 : 0)) % MOD; // Add new back
    return current_hash;
}

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
    // cout << "Input result: ";
    // for(int i=0;i<n;++i) {
    //     cout << arr[i] << ' ';
    // }
    // cout << '\n';
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
    // cout << "preprocess result: ";
    // for(int i=0;i<n;++i) {
    //     cout << (brr[i]?1:0) << ' ';
    // }
    // cout << '\n';
}

void work() {
    size_t base_power=1;
    for(int i=0;i<n-1;++i) base_power = (base_power * BASE) % MOD;

    size_t deqHashVal = compute_hash(brr);
    s.insert(deqHashVal);

    // cout << "Initial deque and hash: ";
    // for (bool b : deq) cout << (b ? 1 : 0) << ' ';
    // cout << "Hash: " << deqHashVal << '\n';

    for(int i=0;i<n-1;++i) {
        deqHashVal=roll_hash(deqHashVal, brr[i], brr[i], base_power);
        s.insert(deqHashVal);
        // cout << "After rotation " << i << ": ";
        // for (bool b : deq) cout << (b ? 1 : 0) << ' ';
        // cout << "Hash: " << deqHashVal << '\n';
    }
    Answer=s.size();
}

int main(int argc, char** argv)
{
    setbuf(stdout, NULL);
    cin.tie(NULL); ios_base::sync_with_stdio(false);
	int T, test_case;
    s.rehash(500001); // This prevents in average the number of rehashing (O(n)).
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
		cout << "Case #" << test_case+1 << '\n';
		cout << Answer << '\n';
	}

	return 0;//Your program should return 0 on normal termination.
}