#include<bits/stdc++.h>
using namespace std;
#define int long long

int tree[2000005];
int tag[2000005];
int a[1000005];

int n,m;

void build(int num,int l,int r)
{
	if(l==r)
	{
		tree[num]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(num*2,l,mid);
	build(num*2+1,mid+1,r);
	tree[num]=tree[num*2]+tree[num*2+1];
}
void add(int num,int l,int r,int op)
{
	tag[num]+=op;
	tree[num]+=op*(r-l+1);
}

void resolve(int num,int l,int r)
{
	int op=tag[num];
	int mid=(l+r)/2;
	tag[num]=0;
	add(num*2,l,mid,op);
	add(num*2+1,mid+1,r,op);
}
void update(int nl,int nr,int k,int num,int l,int r)
{
	if(nl<=l&&nr>=r)
	{
		tag[num]+=k;
		tree[num]+=k*(r-l+1);
		return;
	}
	int mid=(l+r)/2;
	resolve(num,l,r);
	if(nl<=mid) update(nl,nr,k,num*2,l,mid);
	if(nr>=mid+1) update(nl,nr,k,num*2+1,mid+1,r);
	tree[num]=tree[num*2]+tree[num*2+1];
}
int query(int nl,int nr,int num,int l,int r)
{
	if(nl<=l&&nr>=r) return tree[num];
	int mid=(l+r)/2;
	resolve(num,l,r);
	int ans=0;
	if(nl<=mid) ans+=query(nl,nr,num*2,l,mid);
	if(nr>=mid+1) ans+=query(nl,nr,num*2+1,mid+1,r);
	return ans;
}

signed main()
{
	cin >> n >>m;
	for(int i=1;i<=n;i++) cin >> a[i];
	memset(tree,0,sizeof(tree));
	memset(tag,0,sizeof(tag));
	build(1,1,n);
	for(int i=0;i<m;i++)
	{
		int t,x,y,z;
		cin >> t >> x >> y;
		if(t==1)
		{
			cin >> z;
			update(x,y,z,1,1,n);
		}
		else
		{
			cout<<query(x,y,1,1,n)<<endl;
		}
	}
    return 0;
}
