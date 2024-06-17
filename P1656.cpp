#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
pair<int,int> a[5005];
int f[160];
int g;
int go(int t)
{
    if(f[t]==t) return t;
    return f[t]=go(f[t]);
}

void merge(int a,int b)
{
    int x=go(a),y=go(b);
    if(x!=y)
    {
        g--;
        f[x]=y;
    }
}

signed main()
{
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> a[i].first >> a[i].second;
        if(a[i].first>a[i].second)
        {
            swap(a[i].first,a[i].second);
        }
    }
    sort(a+1,a+m+1);
    for(int i=1;i<=m;i++)
    {
        g=n;
        for(int j=1;j<=n;j++) f[j]=j;
        for(int j=1;j<=m;j++)
        {
            if(j==i) continue;
            merge(a[j].first,a[j].second);
        }
        if(g>1)
        {
            cout<<a[i].first<<" "<<a[i].second<<endl;
        }
    }
    return 0;
}
