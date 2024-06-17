#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
int fight[20005];
int f[20005];

struct gh
{
    int num;
    int a,b;
} a[100005];

int cmp(gh a,gh b)
{
    return a.num>b.num;
}

int go(int t)
{
    if(f[t]==t) return t;
    return f[t]=go(f[t]);
}

signed main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin >> a[i].a>>a[i].b>>a[i].num;
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        int x=a[i].a,y=a[i].b;
        if(go(x)==go(y))
        {
            cout<<a[i].num;
            return 0;
        }
        if(fight[x]==0) fight[x]=y;
        else
        {
            int op=go(fight[x]);
            f[go(y)]=op;
        }
        if(fight[y]==0) fight[y]=x;
        else
        {
            int op=go(fight[y]);
            f[go(x)]=op;
        }
    }
    cout<<0;
    return 0;
}
