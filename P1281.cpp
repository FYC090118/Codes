#include<bits/stdc++.h>
using namespace std;
#define int long long

int m,k;
int a[505];

stack<pair<int,int> > ans;

int check(int t)
{
    int cnt=1;
    int now=0;
    for(int i=1;i<=m;i++)
    {
        if(now+a[i]>t)
        {
            cnt++;
            now=0;
            if(cnt>k) return 0;
        }
        now+=a[i];
    }
    return 1;
}

signed main()
{
    cin >> m >> k;
    int minn=0x3f3f3f3f,maxx=0;
    for(int i=1;i<=m;i++)
    {
        cin >> a[i];
        maxx+=a[i];
        minn=min(minn,a[i]);
    }
    while(minn<=maxx)
    {
        int mid=(minn+maxx)/2;
        if(check(mid)) maxx=mid-1;
        else minn=mid+1;
    }
    int last=m;
    int now=a[m];
    for(int i=m-1;i>=1;i--)
    {
        if(now+a[i]>minn)
        {
            ans.push(make_pair(i+1,last));
            last=i;
            now=0;
        }
        now+=a[i];
    }
    ans.push(make_pair(1,last));
    while(ans.size())
    {
        pair<int,int> op=ans.top();
        ans.pop();
        cout<<op.first<<' '<<op.second<<endl;
    }
    return 0;
}

