#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m;

vector<int> a[1005];
vector<int> tim[1005];

int vs[1005];  
int ds[1005];
int cnt[1005];
queue<int> Q;

void spfa(int s) {
	memset(ds, 0x3f, sizeof(ds));
	Q.push(s);
	ds[s] = 0;
	vs[s] = 1;//在队列里 
	while(Q.size()) {
		int nw = Q.front();//取队头 
		Q.pop();
        cnt[nw]++;
        if(cnt[nw]>=n)
        {
            cout<<"NO SOLUTION";
            exit(0);
        }
		vs[nw] = 0;//nw不在队列里 
		for(int i = 0; i < a[nw].size(); ++i) {
			if(ds[a[nw][i]] > ds[nw] + tim[nw][i]) {
				ds[a[nw][i]] = ds[nw] + tim[nw][i];
				if(vs[a[nw][i]] == 0) {//如果不在队列里就入队 
					Q.push(a[nw][i]);
					vs[a[nw][i]] = 1;
				} 
			}
		}
	}
}

signed main()
{
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a[y].push_back(x);
        tim[y].push_back(z);
    }
    for(int i=1;i<=n;i++)
    {
        a[0].push_back(i);
        tim[0].push_back(i);
    }
    spfa(0);
    int minn=0x3f3f3f3f;
    for(int i=1;i<=n;i++) minn=min(minn,ds[i]);
    for(int i=1;i<=n;i++) cout<<ds[i]-minn<<endl;
    return 0;
}

