#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int n;
double x[1005],y[1005];
int num[1005];

double dis(int a,int b)
{
    return sqrtl((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

double maxx[1005][1005][2];
int pre[1005][1005][2];

int sol(int x,int y,int z)
{
    return x*100000+y*10+z;
}

void dfs(int x,int y,int z)
{
    if(pre[x][y][z]==0)
    {
        cout<<num[x]<<' ';
        return;
    }
    dfs(pre[x][y][z]/100000,pre[x][y][z]%100000/10,pre[x][y][z]%10);
    if(z==0) cout<<num[x]<<' ';
    else cout<<num[y]<<' ';
}

signed main()
{
    cin >> n;
    double maxxx=-9999999;
    int k;
    for(int i=1;i<=n;i++)
    {
        cin >> x[i] >> y[i];
        num[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            maxx[i][j][0]=999999999999;
            maxx[i][j][1]=999999999999;
            pre[i][j][0]=-1;
            pre[i][j][1]=-1;
            if(j==n) continue;
            if(x[j]>x[j+1])
            {
                swap(x[j],x[j+1]);
                swap(y[j],y[j+1]);
                swap(num[j],num[j+1]);
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(y[i]>maxxx)
        {
            maxxx=y[i];
            k=i;
        }
    }
    maxx[k][k][0]=0;
    maxx[k][k][1]=0;
    pre[k][k][0]=0;
    pre[k][k][1]=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=max((int)1,k-i+1);j<=min(k,n-i+1);j++)
        {
            if(maxx[j+1][j+i-1][0]+dis(j+1,j)<maxx[j][j+i-1][0])
            {
                maxx[j][j+i-1][0]=maxx[j+1][j+i-1][0]+dis(j+1,j);
                pre[j][j+i-1][0]=sol(j+1,j+i-1,0);
            }
            if(maxx[j][j+i-2][0]+dis(j,j+i-1)<maxx[j][j+i-1][1])
            {
                maxx[j][j+i-1][1]=maxx[j][j+i-2][0]+dis(j,j+i-1);
                pre[j][j+i-1][1]=sol(j,j+i-2,0);
            }
            if(maxx[j+1][j+i-1][1]+dis(j+i-1,j)<maxx[j][j+i-1][0])
            {
                maxx[j][j+i-1][0]=maxx[j+1][j+i-1][1]+dis(j+i-1,j);
                pre[j][j+i-1][0]=sol(j+1,j+i-1,1);
            }
            if(maxx[j][j+i-2][1]+dis(j+i-2,j+i-1)<maxx[j][j+i-1][1])
            {
                maxx[j][j+i-1][1]=maxx[j][j+i-2][1]+dis(j+i-1,j+i-2);
                pre[j][j+i-1][1]=sol(j,j+i-2,1);
            }
        }
    }
    if(maxx[1][n][0]>maxx[1][n][1]) dfs(1,n,1);
    else dfs(1,n,0);
    return 0;
}
