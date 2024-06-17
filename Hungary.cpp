#include <bits/stdc++.h>
using namespace std;
#define int long long

struct graph
{
	bool con[40005];
	vector<int> a[40005];
	int match[40005];
	int colo[40005];
	void push(int x,int y)
	{
		a[x].push_back(y);
	}
	bool find(int x)
	{
	    for(int i=0;i<a[x].size();i++)
	    {
	        int j = a[x][i];
	        if (!con[j])
	        {
	            con[j] = true;
	            if (match[j] == 0||find(match[j]))
	            {
	                match[j] = x;
	                return true;
	            }
	        }
	    }
	    return false;
	}
	int hungary(int all)
	{
		memset(match,0,sizeof(match));
		int result=0;
		for(int i=1;i<=all;i++)
		{
			memset(con,0,sizeof(con));
			if(find(i)) result++;
		}
		return result/2;
	}
	int check(int t,int col)
	{
		for(int i=0;i<a[t].size();i++)
		{
			if(colo[a[t][i]]==col) return 1;
		}
		return 0;
	}
	int color(void)
	{
		queue<pair<int,int> > col;
		memset(colo,0,sizeof(colo));
		col.push(make_pair(1,1));
		while(col.size())
		{
			pair<int,int> t=col.front();
			col.pop();
			int op=t.first;
			if(check(op,t.second)) return 1;
			colo[op]=t.second;
			for(int i=0;i<a[op].size();i++)
			{
				if(colo[a[op][i]]==0) col.push(make_pair(a[op][i],3-t.first));
			}
		}
		return 0;
	}
}G;

signed main()
{
	return 0;
}
