#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Big//高精结构体 
{
	string t;//数字，用字符串存储 
	int opk;//符号 
	void read()//读入数字 
	{
		opk=1;
		t="";
		char ch=getchar();
		while(!isdigit(ch))
		{
			if(ch=='-') opk=-1;
			ch=getchar();
		}
		while(isdigit(ch))
		{
			t+=ch;
			ch=getchar();
		}
	}
	void print()//输出数字 
	{
		if(opk==-1) cout<<'-';
		cout<<t;
	}
	void init()//数字格式化
	{
		while(t[0]=='0'&&t!="0") t=t.substr(1);
		if(t=="0") opk=1;
	} 
};

Big operator - (Big a,Big b);//处理加法特殊情况 
Big operator + (Big a,Big b)//加法 
{
	if(a.opk!=b.opk)//异号数加法可使用减法处理 
	{
		if(a.opk==-1)
		{
			Big h;
			h.opk=1;
			h.t=a.t;
			return b-h;
		}
		else
		{
			Big h;
			h.opk=1;
			h.t=b.t;
			return a-h;
		}
	}
	//高精加法 
	string ax=a.t,bx=b.t;
	while(bx.length()<ax.length()) bx='0'+bx;
	while(ax.length()<bx.length()) ax='0'+ax;
	reverse(ax.begin(),ax.end());
	reverse(bx.begin(),bx.end());
	string c="";
	int op=0;
	for(int i=0;i<ax.length();i++)
	{
		int t=ax[i]+bx[i]-'0'-'0'+op;
		c+=char(t%10+'0');
		op=t/10;
	}
	if(op) c+='1';
	reverse(c.begin(),c.end());
	Big x;
	x.t=c;
	x.opk=a.opk;
	if(c=="0") x.opk=1;
	return x;
}

bool operator <(Big a,Big b)//高精小于 
{
	if(a.opk!=b.opk) return a.opk<b.opk;//符号 
	if(a.opk==-1)//负数处理 
	{
		if(a.t.length()!=b.t.length()) return a.t.length()>b.t.length();
		else return a.t>b.t;
	}
	if(a.t.length()!=b.t.length()) return a.t.length()<b.t.length();
	else return a.t<b.t;
}

bool operator >(Big a,Big b)//高精大于 
{
	return b<a;
}

bool operator ==(Big a,Big b)//高精等于 
{
	return (a.opk==b.opk)&&(a.t==b.t);
}

bool operator !=(Big a,Big b)//高精不等于 
{
	return !(a==b);
}

bool operator >=(Big a,Big b)//高精大于等于 
{
	return (a>b)||(a==b);
}

bool operator <=(Big a,Big b)//高精小于等于 
{
	return (a<b)||(a==b);
}

Big operator - (Big a,Big b)//减法 
{
	if(a.opk!=b.opk)//异号情况用加法解决 
	{
		Big u;
		u.opk=a.opk;
		u.t=b.t;
		return u+a;
	}
	//高精减法 
	string ax=a.t,bx=b.t;
	Big ans;
	if(a<b)
	{
		ans.opk=-1;
		if(a.opk==1) swap(ax,bx);
	}
	while(bx.length()<ax.length()) bx='0'+bx;
	while(ax.length()<bx.length()) ax='0'+ax;
	reverse(ax.begin(),ax.end());
	reverse(bx.begin(),bx.end());
	string c="";
	int op=0;
	for(int i=0;i<ax.length();i++)
	{
		int t=ax[i]-bx[i]+op;
		if(t<0)
		{
			t+=10;
			op=-1;
		}
		else op=0;
		c+=char(t%10+'0');
	}
	reverse(c.begin(),c.end());
	ans.t=c;
	ans.init();
	return ans;
}

Big operator * (Big a,Big b)//高精乘法 
{
	string ax=a.t,bx=b.t;
	Big ans;
	if(a.opk==b.opk) ans.opk=1;
	else ans.opk=-1;
	int an[100005];
	memset(an,0,sizeof(an));
	reverse(ax.begin(),ax.end());
	reverse(bx.begin(),bx.end());
	string c="";
	for(int i=0;i<ax.length();i++)
	{
		for(int j=0;j<bx.length();j++)
		{
			an[i+j]+=(ax[i]-'0')*(bx[j]-'0');
		}
	}
	for(int i=0;i<=10005;i++)
	{
		c+=char(an[i]%10+'0');
		an[i+1]+=an[i]/10;
	}
	reverse(c.begin(),c.end());
	ans.t=c;
	ans.init();
	return ans;
}

Big operator / (Big a,int b)//高精除以低精 
{
	string ax=a.t;
	Big ans;
	int oplk=(b>0?1:-1);
	if(a.opk==oplk) ans.opk=1;
	else ans.opk=-1;
	b=abs(b);
	string c="";
	int op=0;
	for(int i=0;i<ax.length();i++)
	{
		op=op*10+ax[i]-'0';
		c+=char(op/b+'0');
		op%=b;
	}
	ans.t=c;
	ans.init();
	return ans;
}

Big itoB(int t)//低精转高精 
{
	Big ans;
	if(t<0)
	{
		ans.opk=-1;
		t=-t;
	}
	else ans.opk=1;
	string c="";
	if(t==0) c="0";
	else
	{
		while(t)
		{
			c=char(t%10+'0')+c;
			t/=10;
		}
	}
	ans.t=c;
	return ans;
}

int Btoi(Big f)//高精转低精 
{
	if(f.t.length()>18)//处理高精数过大情况 
	{
		cout<<"Unabled: ";
		f.print();
		cout<<endl;
		return 0;
	}
	int k=f.opk;
	int l=0;
	for(int i=0;i<f.t.length();i++)
	{
		l=l*10+f.t[i]-'0';
	}
	return k*l;
}

Big operator / (Big a,Big b)//高精除以高精(有Bug) 
{
	string as=a.t,k="",ans="";
	Big an;
	an.opk=(a.opk==b.opk);
	b.opk=1;
	int deep=0;
	for(int i=0;i<as.length();i++)
	{
		k+=as[i];
		Big op;
		op.opk=1;
		op.t=k;
		if(op>=b) deep=1;
		if(deep)
		{
			for(int j=0;j<=9;j++)
			{
				Big t=itoB(j);
				Big tx=itoB(j+1);
				if(t*b<=op&&tx*b>op)
				{
					ans+=char(j+'0');
					op=op-t*b;
					op.init();
					k=op.t;
					if(k=="0") k="";
				}
			}
		}
	}
	an.t=ans;
	an.init();
	return an;
}

Big operator % (Big a,Big b)//高精取余高精 
{
	string as=a.t,k="";
	Big an;
	an.opk=(a.opk==b.opk);
	b.opk=1;
	for(int i=0;i<as.length();i++)
	{
		k+=as[i];
		Big op;
		op.opk=1;
		op.t=k;
		if(op>=b)
		{
			for(int j=0;j<=9;j++)
			{
				Big t=itoB(j);
				Big tx=itoB(j+1);
				if(t*b<=op&&tx*b>op)
				{
					op=op-t*b;
					op.init();
					k=op.t;
					if(k=="0") k="";
				}
			}
		}
	}
	if(k=="") k="0";
	an.t=k;
	an.init();
	if(an.opk==-1) an=an+b;
	return an;
}

Big sqrt(Big a)//高精开根 
{
	if(a.opk==-1)
	{
		return itoB(0);
	}
	Big x=a,y=itoB(1);
	while(x>=y)
	{
		Big mid=(x+y)/2;
		if(mid*mid<=a&&(mid+itoB(1))*(mid+itoB(1))>a) return mid;
		if((mid+itoB(1))*(mid+itoB(1))<=a) y=mid+itoB(1);
		else x=mid-itoB(1);
	}
	return itoB(0);
}

Big pow(Big a,Big b)//高精乘方 
{
	if(b.opk==-1)
	{
		return itoB(0);
	}
	Big t=a,ans=itoB(1);
	while(b!=itoB(0))
	{
		if(b%itoB(2)==itoB(1)) ans=ans*t;
		t=t*a;
		b=b/2;
	}
	return ans;
}

signed main()
{
	Big a,b,c;
	a.read();
	b.read();
	c=a*b;
	c.print();
	return 0;
}
