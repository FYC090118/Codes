#include<bits/stdc++.h>
using namespace std;
#define int long long

struct graph
{
    vector<int> to[100005];
    vector<int> cos[100005];
    vector<int> rev[100005];
    int cur[100005];
    int dep[100005];
    int went[100005];
    int s,t;
    int maxflow;
    int vis;
    void clear()
    {
        for(int i=0;i<=100000;i++)
        {
            to[i].clear();
            cos[i].clear();
            rev[i].clear();
        }
        maxflow=0;
    }
    void push(int u,int v,int cost)
    {
        to[u].push_back(v);
        cos[u].push_back(cost);
        rev[u].push_back(to[v].size());
        to[v].push_back(u);
        cos[v].push_back(0);
        rev[v].push_back(to[u].size()-1);
    }
    bool bfs()
    {
        memset(dep,0x3f,sizeof(dep));
        memset(went,0,sizeof(went));
        memset(cur,0,sizeof(cur));
        dep[s]=0;
        queue<int> q;
        q.push(s);
        while(q.size())
        {
            int f=q.front();
            q.pop();
            if(went[f]) continue;
            went[f]=1;
            for(int i=0;i<to[f].size();i++)
            {
                if(dep[to[f][i]]>dep[f]+1&&cos[f][i])
                {
                    dep[to[f][i]]=dep[f]+1;
                    q.push(to[f][i]);
                }
            }
        }
        if(dep[t]==0x3f3f3f3f3f3f3f3f) return 0;
        return 1;
    }
    int dfs(int now,int low)
    {
        int nlow=0;
        if(now==t)
        {
            vis=1;
            maxflow+=low;
            return low;
        }
        int used=0;
        for(int i=cur[now];i<to[now].size();i++)
        {
            cur[now]=i;
            if(cos[now][i]&&dep[to[now][i]]==dep[now]+1)
            {
                nlow=dfs(to[now][i],min(low-used,cos[now][i]));
                if(nlow)
                {
                    used+=nlow;
                    cos[now][i]-=nlow;
                    cos[to[now][i]][rev[now][i]]+=nlow;
                    if(used==low) break;
                }
            }
        }
        return used;
    }
    int dinic(int a,int b)
    {
        s=a,t=b;
        while(bfs())
        {
            vis=1;
            while(vis==1)
            {
                vis=0;
                dfs(s,0x3f3f3f3f3f);
            }
        }
        return maxflow;
    }
} G;

int n,m,s,t;

signed main()
{
    cin >> n >> m >> s >> t;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        G.push(x,y,z);
    }
    cout<<G.dinic(s,t)<<endl;
    return 0;
}
