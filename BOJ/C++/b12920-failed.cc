#include <bits/stdc++.h>
using namespace std;
int w[101], v[101], num[101], arr[10001], nums[10001];
// nums: the least possible number of usage of the material to make ~.
// arr[j]: 총 j의 무게로 가능한 냠냠.
// aha... 이렇게 풀면 안된다!
// 왜냐하면 배낭에 넣는 한 종류의 물건을 적게 포함한 경우도 고려해야 하기 때문.
// 하지만 이건 greedily 고려한 느낌이다!
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;++i) {
        cin >> w[i] >> v[i] >> num[i];
    }
    for(int i=1,j;i<=n;++i) {
        memset(nums, 0, sizeof(nums));
        for(j=w[i];j<=m;++j) if(nums[j-w[i]]<num[i] && arr[j]<arr[j-w[i]]+v[i]) {
            nums[j] = nums[j-w[i]] + 1;
            arr[j] = arr[j-w[i]] + v[i];
        }
    }
    cout << *max_element(arr+1, arr+m+1);

    return 0;
}