#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    char s[101]={}, tmp[101]={};
    const char S[][4]={"dz=", "lj", "nj", "z=", "c=", "c-", "d-", "s="};


    /* T is for Testing
    int T;
    cin >> T;
    while(T--)
    { //*/

        cin >> s;
        int i=-1,n=strlen(s),l=0,cnt=0,wl;
        /// dz=, lj, nj 등 제거
        while(++i<n)
        {
            tmp[l++]=s[i];
            for(const char * word : S) // https://blog.naver.com/ariiseav75/222861352517
            {
                if(strstr(tmp, word)!=NULL)
                {
                    /// word를 한 알파벳으로 간주함.
                    wl=strlen(word);
                    while(wl--)
                    {
                        tmp[--l]='\0';
                    }
                    ++cnt;

                    /// 남은 것들은 알파벳들이므로 count.
                    cnt+=l;
                    l=0;
                    memset(tmp,0,sizeof(tmp));
                }
            }
        }
        /// 나머지는 알파벳이므로 count.
        cnt+=l;
        l=0;
        memset(tmp,0,sizeof(tmp));

        cout << cnt;

    //}
    /**
    boj.kr/2941
    ljes=njak   6
    ddz=z=      3
    nljj        3
    c=c=        2
    dz=ak       3
    */

    return 0;
}
