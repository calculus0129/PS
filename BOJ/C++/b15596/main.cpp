#include <bits/stdc++.h>
using namespace std;
/*
#include <vector>
long long sum(std::vector<int> &a) {
	int i=a.size();
    long long ans = 0;
    while(i--)
    {
        ans+=a[i];
    }
	return ans;
}
*/
long long sum(vector<int> &a)
{
    long long s=0;
    for(auto i=a.begin();i!=a.end();++i)
    {
        s+=*i;
    }
    return s;
}

int main()
{
    vector<int> arr;
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    arr.resize(n);
    for(int i=0;i<n;++i)
    {
        cin >> arr[i];
    }
    cout << sum(arr);
    //cout << ~(1<<31); // 2147483647

    return 0;
}
