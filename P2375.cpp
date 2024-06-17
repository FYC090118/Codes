#include<bits/stdc++.h>
using namespace std;
#define int long long

int nxt[1000005];
int cnt[1000005];

signed main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int ans=1;
		string x;
		cin >> x;
		x='%'+x;
		nxt[1]=0;
		memset(nxt,0,sizeof(nxt));
        memset(cnt,0,sizeof(cnt));
        cnt[1]=1;
		int j=0;
		for(int i=2;i<=x.length()-1;i++)
		{
			while(x[i]!=x[j+1])
			{
				if(j==0) break;
				j=nxt[j];
			}
			if(x[i]==x[j+1])
			{
				j++;
				nxt[i]=j;
			}
			else nxt[i]=0;
            cnt[i]=cnt[j]+1;
		}
        j=0;
        for(int i=1;i<=x.length()-1;i++)
        {
            while(x[j+1]!=x[i])
            {
                if(j==0) break;
                j=nxt[j];
            }
            if(x[j+1]==x[i]) j++;
            while(j*2>i) j=nxt[j];
            ans=ans%1000000007*(cnt[j]+1)%1000000007;
        }
		cout<<ans<<endl;
	}
}