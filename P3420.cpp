#include<bits/stdc++.h>
using namespace std;
#define int long long

int f[1000005];

int go(int t)
{
    if(f[t]==t) return t;
    return f[t]=go(f[t]);
}

int n;

signed main()
{
    cin >> n;
    int cnt=n;
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin >> k;
        int x=go(i);
        int y=go(k);
        if(x!=y)
        {
            f[x]=y;
            cnt--;
        }
    }
    cout<<cnt;
    return 0;
}
