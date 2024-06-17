#include<bits/stdc++.h>
using namespace std;
#define int long long

int f[5000005];
int n,m,k;

int go(int t)
{
    if(f[t]==t) return t;
    return f[t]=go(f[t]);
}

queue<pair<int,int> > q;

signed main()
{
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        if(x>k&&y>k)
        {
            int op1=go(x);
            int op2=go(y);
            if(op1==op2) continue;
            f[op1]=op2;
        }
        else q.push(make_pair(x,y));
    }
    int cnt=0;
    while(!q.empty())
    {
        pair<int,int> op=q.front();
        q.pop();
        int x=op.first,y=op.second;
        int op1=go(x),op2=go(y);
        if(op1==op2) cnt++;
        else f[op1]=op2;
    }
    cout<<cnt;
    return 0;
}
