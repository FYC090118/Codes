#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[1001];

inline int read()
{
    int x=0;
    char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch))
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}

void write(int t)
{
    if(t>=10) write(t/10);
    putchar(t%10+'0');
}

signed main()
{
    a[1]=1;
    a[2]=2;
    for(int i=3;i<=100;i++) a[i]=a[i-1]+a[i-2];
    int t;
    t=read();
    while(t--)
    {
        int k;
        k=read();
        int cnt=0;
        while(k)
        {
            int u=upper_bound(a+1,a+101,k)-a;
            k=min(k-a[u-1],a[u]-k);
            cnt++;
        }
        write(cnt);
        cout<<endl;
    }
    return 0;
}
