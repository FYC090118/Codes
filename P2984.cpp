#include<bits/stdc++.h>
using namespace std;
struct graph {
	int vs[100005]; //ĳ�������·�Ƿ񱻱��Ϊ�������· 
	int ds[100005]; // ���·�ı�Ȩ�� 
	vector<int> E[100005];
	vector<int> V[100005];
	priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > PQ;//����С���� 
	void push(int x, int y, int z) {
		E[x].push_back(y);//�ӱ� 
		V[x].push_back(z); 
	}
	void dijkstra(int s) {
		memset(ds, 0x3f, sizeof(ds)); //��ʼ������� 
		memset(vs, 0, sizeof(vs));//��ʼ��� 
		ds[s] = 0;
		PQ.push(make_pair(ds[s], s));//������ӵ����� 
		while(PQ.size()) {
			int nw = PQ.top().second;//ȡ�Ѷ�Ԫ�صı�� 
			PQ.pop();
			if(vs[nw] == 1) continue;//����Ѿ���ȡ����˵����Ԫ������ 
			vs[nw] = 1;//��Ǳ�ȡ�� 
			for(int i = 0; i < E[nw].size(); ++i) {
				int k = E[nw][i];//k�������ߵ��յ� 
				int w = V[nw][i];//w�������ߵı�Ȩ 
				if(ds[k] > ds[nw] + w) {//�������· 
					ds[k] = ds[nw] + w;
					PQ.push(make_pair(ds[k], k));
					//������·�������ˣ��Ͱ��µ�ֵ�ӵ����� 
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
