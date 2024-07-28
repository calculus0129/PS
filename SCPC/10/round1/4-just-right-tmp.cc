/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
int n, l, arr[101010], brr[101010];

// void init() {
// }

void input() {
    // init();
    cin >> n >> l;
    for(int i=0;i<n;++i) {
        cin >> arr[i];
    }
    for(int i=0;i<n;++i) {
        cin >> brr[i];
    }
    sort(arr, arr+n);
    sort(brr, brr+n);
}

bool valid(int val) {
    return -l<=val && val<=l;
}

int cmp(int val, int tgt) {
    if(val>l) return 1;
    else if(val<-l) return -1;
    if(val>tgt) return 1;
    else if(val<tgt) return -1;
    return 0;
}

// dif is the value of B's-A's.
bool check(int dif, bool bigger) {
    int i=0,j=0,d;
    while(i<n && j<n) {
        d = brr[i]-arr[j];
        if(valid(d)) {
            if(bigger && cmp(d, dif)<0) {
                ++i;
            } else if(!bigger && cmp(d, dif)>0) {
                ++j;
            } else {
                return true;
            }
        }
        else {
            if(cmp(d, dif)<0) ++i;
            else ++j;
        }
    }
    return false;
}

bool check(int dif) {
    assert(dif>=0);
    return check(dif, true) || check(-dif, false);
}

int work(int hi) {
    int lo=0, mid;
    if(check(hi)) return hi;
    if(!check(lo)) return -1;
    // Now, check(lo) == true, check(hi) == false.
    while(lo+1<hi) {
        mid = lo+hi>>1;
        if(check(mid)) lo=mid;
        else hi=mid;
    }
    return lo;
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
        input();
		cout << "Case #" << test_case+1 << endl;
		cout << work(l) << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}



// int cmp(int val, int lo, int hi) {
//     assert(lo<=hi);
//     if(lo<=val && val<=hi) return 0;
//     if(val<lo) return -1;
//     return 1;
// }

// // Check if there is a possible difference within the range.
// // Only among the permutations whose difference results in the range -l to l
// // dif is the value of B's-A's.
// bool check(int lo, int hi) {
//     int i=0,j=0,d,a;
//     while(i<n && j<n) {
//         d = brr[i]-arr[j];
//         a = cmp(d, -l, l);
//         if(a==0) a = cmp(d, lo, hi);
//         if(a==0) return true;
//         if(a<0) ++i;
//         else ++j;
//     }
//     return false;
// }

// // Check if the upperbound can be the upper bound
// // of the differences.
// bool check(int upperbound) {
//     assert(upperbound>=0);
//     return !check(-INT_MAX, -upperbound-1) && !check(upperbound+1, INT_MAX);
// }

// int work(int hi) {
//     // DEFINITION OF MAX under finite set S: sup S.
//     // i.e. the lowest upper bound of S.
//     // Hence we design the check(int v) to see
//     // if v can be the lowest upper bound of the differences.
//     // Then, lo~somewhere would be false,
//     // somewhere+1~hi would be true.
//     // By definition of the lowest upper bound,
//     // we choose the 'somewhere'+1 as the answer.
//     int lo=0, mid;
//     if(check(lo)) return hi;
//     if(!check(lo)) return -1;
//     // Now, check(lo) == true, check(hi) == false.
//     while(lo+1<hi) {
//         mid = lo+hi>>1;
//         if(check(mid)) lo=mid;
//         else hi=mid;
//     }
//     return lo;
// }

// int main(int argc, char** argv)
// {
// 	int T, test_case;
//     setbuf(stdout, NULL);
//     cin.tie(NULL); ios_base::sync_with_stdio(false);
// 	/*
// 	   The freopen function below opens input.txt file in read only mode, and afterward,
// 	   the program will read from input.txt file instead of standard(keyboard) input.
// 	   To test your program, you may save input data in input.txt file,
// 	   and use freopen function to read from the file when using cin function.
// 	   You may remove the comment symbols(//) in the below statement and use it.
// 	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
// 	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
// 	 */	

// 	// freopen("input.txt", "r", stdin);
// 	cin >> T;
// 	for(test_case = 0; test_case  < T; test_case++)
// 	{
// 		/////////////////////////////////////////////////////////////////////////////////////////////
// 		/*
// 		   Implement your algorithm here.
// 		   The answer to the case will be stored in variable Answer.
// 		 */
// 		/////////////////////////////////////////////////////////////////////////////////////////////
// 		// Print the answer to standard output(screen).
//         input();
// 		cout << "Case #" << test_case+1 << endl;
// 		cout << work(l) << endl;
// 	}

// 	return 0;//Your program should return 0 on normal termination.
// }