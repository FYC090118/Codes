#include<bits/stdc++.h>
using namespace std;
#define int long long

priority_queue<int> k;

signed main()
{
    int n;
    cin >> n;
    int t;
    cin >> t;
    k.push(t);
    int ans=0;
    for(int i=2;i<=n;i++)
    {
        cin >> t;
        k.push(t);
        if(t<k.top())
        {
            ans+=k.top()-t;
            k.pop();
            k.push(t);
        }
    }
    cout<<ans;
    return 0;
}
