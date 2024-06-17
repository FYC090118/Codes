#include<bits/stdc++.h>
using namespace std;
#define int long long

int nxt[1000005];
string s,t;

signed main()
{
    cin >> s >> t;
    s='%'+s;
    t='%'+t;
    int j=0;
    for(int i=2;i<=t.length()-1;i++)
    {
        while(j&&t[j+1]!=t[i]) j=nxt[j];
        j+=(t[j+1]==t[i]);
        nxt[i]=j;
    }
    j=0;
    for(int i=1;i<=s.length()-1;i++)
    {
        while(j&&t[j+1]!=s[i]) j=nxt[j];
        j+=(t[j+1]==s[i]);
        if(j==t.length()-1)
        {
            cout<<i-t.length()+2<<endl;
            j=nxt[j];
        }
    }
    for(int i=1;i<=t.length()-1;i++) cout<<nxt[i]<<' ';
    return 0;
}
