#include<bits/stdc++.h>
using namespace std;
#define int long long

struct graph
{
    vector<int> to[2005];
    vector<int> cos[2005];
    vector<int> rev[2005];
    vector<int> pri[2005];
    int cur[2005];
    int dep[2005];
    int went[2005];
    int s,t;
    int maxflow;
    int vis;
    int mincost=0;
    void clear()
    {
        for(int i=0;i<=2000;i++)
        {
            to[i].clear();
            cos[i].clear();
            rev[i].clear();
        }
        maxflow=0;
    }
    void push(int u,int v,int cost,int price)
    {
        to[u].push_back(v);
        cos[u].push_back(cost);
        rev[u].push_back(to[v].size());
        pri[u].push_back(price);
        to[v].push_back(u);
        cos[v].push_back(0);
        rev[v].push_back(to[u].size()-1);
        pri[v].push_back(-price);
    }
    bool spfa()
    {
        memset(dep,0x3f,sizeof(dep));
        memset(went,0,sizeof(went));
        memset(cur,0,sizeof(cur));
        dep[s]=0;
        went[s]=1;
        queue<int> q;
        q.push(s);
        while(q.size())
        {
            int f=q.front();
            q.pop();
            went[f]=0;
            for(int i=0;i<to[f].size();i++)
            {
                if(dep[to[f][i]]>dep[f]+pri[f][i]&&cos[f][i])
                {
                    dep[to[f][i]]=dep[f]+pri[f][i];
                    if(went[to[f][i]]==0)
                    {
                        went[to[f][i]]=1;
                        q.push(to[f][i]);
                    }
                    
                }
            }
        }
        if(dep[t]==0x3f3f3f3f3f3f3f3f) return 0;
        return 1;
    }
    int dfs(int now,int low)
    {
        if(went[now]) return 0;
        went[now]=1;
        int nlow=0;
        if(now==t)
        {
            vis=1;
            maxflow+=low;
            went[now]=0;
            return low;
        }
        int used=0;
        for(int i=cur[now];i<to[now].size();i++)
        {
            cur[now]=i;
            if(cos[now][i]&&dep[to[now][i]]==dep[now]+pri[now][i])
            {
                nlow=dfs(to[now][i],min(low,cos[now][i]));
                if(nlow)
                {
                    used+=nlow;
                    cos[now][i]-=nlow;
                    cos[to[now][i]][rev[now][i]]+=nlow;
                    mincost+=pri[now][i];
                    if(used==nlow) break;
                }
            }
        }
        went[now]=0;
        return used;
    }
    int dinic(int a,int b)
    {
        s=a,t=b;
        while(spfa())
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
    return 0;
}