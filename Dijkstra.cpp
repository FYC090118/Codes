#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,z,s;
struct graph {
	int vs[100005];
	int ds[100005];
	vector<int> E[100005];
	vector<int> V[100005];
	priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > PQ;//定义小根堆 
	void push(int x, int y, int z) {
		E[x].push_back(y);
		V[x].push_back(z); 
	}
	void dijkstra(int s) {
		memset(ds, 0x3f, sizeof(ds));
		memset(vs, 0, sizeof(vs));
		ds[s] = 0;
		PQ.push(make_pair(ds[s], s));
		while(PQ.size()) {
			int nw = PQ.top().second;
			PQ.pop();
			if(vs[nw] == 1) continue;
			vs[nw] = 1;
			for(int i = 0; i < E[nw].size(); ++i) {
				int k = E[nw][i];
				int w = V[nw][i];
				if(ds[k] > ds[nw] + w) {
					ds[k] = ds[nw] + w;
					PQ.push(make_pair(ds[k], k));
				}
			}
		}
	}
}G; 
int main() {
	cin >> n >> m >> s;
	for(int i = 1; i <= m; ++i) {
		cin >> x >> y >> z;
		G.push(x, y, z);
	}
	G.dijkstra(s);
	for(int i = 1; i <= n; ++i) {
		if(G.ds[i] == 0x3f3f3f3f) G.ds[i] = 2147483647;
		cout<<G.ds[i]<<' ';
	}
	return 0;
}
