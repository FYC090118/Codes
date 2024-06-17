#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
int a[100005];

signed main()
{
	cin >> n;
	int op=1,maxx=0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		maxx=max(maxx,a[i]);
	}
	while(op<=maxx)
	{
		int r[200005];
		int cnt[10];
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
		{
			int t=a[i]/op%10;
			cnt[t]++;
		}
		for(int i=1;i<=9;i++) cnt[i]+=cnt[i-1];
		for(int i=9;i>=1;i--) cnt[i]=cnt[i-1]+1;
		cnt[0]=1;
		for(int i=1;i<=n;i++)
		{
			int t=a[i]/op%10;
			r[cnt[t]]=a[i];
			cnt[t]++;
		}
		for(int i=1;i<=n;i++) a[i]=r[i];
		op*=10;
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	return 0;
}
