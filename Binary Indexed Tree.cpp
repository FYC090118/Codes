#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define int long long

int n,m;
int tree[500005];
int lowbit(int t)
{
	return t&(-t);
}

void update(int x,int k)
{
	for(int i=x;i<=n;i+=lowbit(i))
	{
		tree[i]+=k;
	}
}

int query(int t)
{
	int ans=0;
	for(int i=t;i>=1;i-=lowbit(i)) ans+=tree[i];
	return ans;
}
signed main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin >> t;
		update(i,t);
	}
	for(int i=0;i<m;i++)
	{
		int t,x,y;
		cin >> t >> x >> y;
		if(t==1) update(x,y);
		else cout<<query(y)-query(x-1)<<endl;
	}
    return 0;
}
