#include<bits/stdc++.h>
using namespace std;
#define int long long

int in[505];
int a[505][505];

stack<int> ans;

int n,m;

void go(int t)
{
    for(int i=1;i<=n;i++)
    {
        while(a[t][i])
        {
            a[t][i]--;
            a[i][t]--;
            go(i);
        }
    }
    ans.push(t);
}

signed main()
{
    cin >> m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin >> x >> y;
        n=max(n,max(x,y));
        in[x]++;
        in[y]++;
        a[x][y]++;
        a[y][x]++;
    }
    int be=1;
    for(int i=1;i<=n;i++)
    {
        if(in[i]%2)
        {
            be=i;
            break;
        }
    }
    go(be);
    while(ans.size())
    {
        cout<<ans.top()<<endl;
        ans.pop();
    }
    return 0;
}
