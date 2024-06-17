#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

inline int read()
{
    int x=0,p=1;
    char ch=getchar();
    while(!isdigit(ch))
    {
        if(ch=='-') p=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*p;
}

int n,m;
int dg[500005];
int now[500005];
int op[500005];
int ned;
int num;

signed main()
{
    srand(time(0));
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        op[i]=rand()*rand()+rand();
        ned+=op[i];
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin >> x >> y;
        now[y]+=op[x];
        dg[y]+=op[x];
        num+=op[x];
    }
    int q;
    cin >> q;
    for(int i=1;i<=q;i++)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int u,v;
            cin >> u >> v;
            now[v]-=op[u];
            num-=op[u];
        }
        else if(t==2)
        {
            int x;
            cin >> x;
            num-=now[x];
            now[x]=0;
        }
        else if(t==3)
        {
            int u,v;
            cin >> u >> v;
            now[v]+=op[u];
            num+=op[u];
        }
        else{
            int x;
            cin >> x;
            num+=dg[x]-now[x];
            now[x]=dg[x];
        }
        if(num==ned) cout<<"YES\n";
        else cout<<"NO\n";
    }
}