#include <iostream>
#define INT_MIN (-2147483647 - 1) // necessary in BOJ!
#define INT_MAX 2147483647 // necessary in BOJ!
#include <functional>
int main()
{
    // https://blog.koriel.kr/modern-cpp-lambdayi-teugjinggwa-sayongbeob/
    std::function<int (const int, const int)> min = [](const int &a, const int &b) -> int
    {
        return (a<b)?a:b;
    },
    max = [](const int &a, const int &b) -> int
    {
        return (a<b)?b:a;
    };
    std::cin.tie(0)->sync_with_stdio(0);

    int now[2][3], nxt[2][3];
    std::function<int (const int *)> min_element = [min](const int arr[]) -> int
    {
        return min(min(arr[0], arr[1]), arr[2]);
    }, max_element = [max](const int arr[]) -> int
    {
        return max(max(arr[0], arr[1]), arr[2]);
    };

    for(int i=0, j;i<2;++i) for(j=0;j<3;++j) nxt[i][j]=0;
    int mi, ma, n, a;

    std::cin>>n;
    n--;
    for(int i=0;i<3;++i)
    {
        std::cin>>a;
        now[0][i] = now[1][i] = a;
    }
    while(n--)
    {
        //std::cin>>inp[0]>>inp[1]>>inp[2];
        for(int i=0, s, e;i<3;++i)
        {
            std::cin>>a;
            mi=INT_MAX, ma=INT_MIN;
            for(s=max(0, i-1), e=min(2, i+1);s<=e;++s)
            {
                mi = min(mi, now[0][s]);
                ma = max(ma, now[1][s]);
            }
            nxt[0][i] = a+mi;
            nxt[1][i] = a+ma;
        }
        std::swap(now, nxt);
    }
    std::cout << max_element(now[1]) << " " << min_element(now[0]);
    return 0;
}

/*pair<int,int> work(vector<vector<int>> &arr, int n)
{
    int now[2][3], a, b, nxt[2][3];
    memset(nxt, 0, sizeof(nxt));
    for(int i=0, j, s, e;i<n;++i)
    {
        swap(now, nxt);
        for(j=0;j<3;++j)
        {
            s = max(j-1, 0);
            e = min(j+1, 2);
            a = now[0][s];
            b = now[1][s];
            for(s=s+1;s<=e;++s)
            {
                a = max(a, now[0][s]);
                b = min(b, now[1][s]);
            }
            nxt[0][j] = arr[i][j]+a;
            nxt[1][j] = arr[i][j]+b;
        }
    }
    return make_pair(*max_element(nxt[0], nxt[0]+3), *min_element(nxt[1], nxt[1]+3));
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3, 0));
    for(auto &a : arr) cin >> a[0] >> a[1] >> a[2];
    pair<int,int> ans = work(arr, n);
    cout << ans.first << " " << ans.second;

    return 0;
}
*/
