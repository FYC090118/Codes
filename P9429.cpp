#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,k,s;

signed main()
{
    cin >> n >> m >> k >> s;
    int d=s/n;
    for(int i=0;i<s-d*n;i++) cout<<d+1<<' ';
    for(int i=0;i<n-s+d*n;i++) cout<<d<<' ';
    return 0;
}
