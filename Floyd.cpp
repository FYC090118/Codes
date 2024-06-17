#include <bits/stdc++.h>
using namespace std;
int n,x,y,m,s,z; 
struct graph {
	int mp[1005][1005];
	int ds[1005][1005];
	void push(int x, int y, int z) {
		mp[x][y] = min(mp[x][y], z);
	}
	void floyd() {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				ds[i][j] = mp[i][j];
			}
		}
		for(int i = 1; i <= n; ++i) ds[i][i] = 0;
		for(int k = 1; k <= n; ++k) {
			for(int i = 1; i <= n; ++i) {
				for(int j = 1; j <= n; ++j) {
					ds[i][j] = min(ds[i][j], ds[i][k] + ds[k][j]);
				}
			}
		}
		
	}
}G; 
int main() {
	cin >> n >> m >> s;
	memset(G.mp, 0x3f, sizeof(G.mp));
	for(int i = 1; i <= m; ++i) {
		cin >> x >> y >> z;
		G.push(x, y, z);
	}
	G.floyd();
	for(int i = 1; i <= n; ++i) {
		if(G.ds[s][i] == 0x3f3f3f3f) G.ds[s][i] = 2147483647;
		cout<<G.ds[s][i]<<' ';
	}
	return 0;
}
