#include<bits/stdc++.h>
using namespace std;
struct graph {
	int vs[100005]; //某个点最短路是否被标记为最终最短路 
	int ds[100005]; // 最短路的边权和 
	vector<int> E[100005];
	vector<int> V[100005];
	priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > PQ;//定义小根堆 
	void push(int x, int y, int z) {
		E[x].push_back(y);//加边 
		V[x].push_back(z); 
	}
	void dijkstra(int s) {
		memset(ds, 0x3f, sizeof(ds)); //初始是无穷大 
		memset(vs, 0, sizeof(vs));//初始清空 
		ds[s] = 0;
		PQ.push(make_pair(ds[s], s));//把起点扔到堆里 
		while(PQ.size()) {
			int nw = PQ.top().second;//取堆顶元素的编号 
			PQ.pop();
			if(vs[nw] == 1) continue;//如果已经被取过，说明该元素作废 
			vs[nw] = 1;//标记被取过 
			for(int i = 0; i < E[nw].size(); ++i) {
				int k = E[nw][i];//k是这条边的终点 
				int w = V[nw][i];//w是这条边的边权 
				if(ds[k] > ds[nw] + w) {//更新最短路 
					ds[k] = ds[nw] + w;
					PQ.push(make_pair(ds[k], k));
					//如果最短路被更新了，就把新的值加到堆里 
				}
			}
		}
	}
}G; 

int n,m,b;

int main() {
	cin >> n >> m >> b;
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        G.push(x,y,z);
        G.push(y,x,z);
    }
    G.dijkstra(1);
    for(int i=0;i<b;i++)
    {
        int x,y;
        cin >> x >> y;
        cout<<G.ds[x]+G.ds[y]<<endl;
    }
	return 0;
}
