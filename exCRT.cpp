/*
x ≡a1 (mod m1)
x ≡a2 (mod m2)
=> x=h1*a1+m1; x=h2*a2+m2
=> h1*a1+m1=h2*a2+m2
=> h1*a1+h2*(-a2)=m2-m1
可用exgcd求解 
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    int n;
    scanf("%d", &n);
    LL a1, m1, a2, m2;
    scanf("%lld%lld", &a1, &m1);
    bool no = false;
    for (int i = 1; i < n; i ++ )
    {
        scanf("%lld%lld", &a2, &m2);
        LL k1, k2;
        LL d = exgcd(a1, a2, k1, k2);
        if ((m2 - m1) % d)
        {
            no = true;
            break;
        }
        LL t = a2 / d;
        k1 = k1 * (m2 - m1) / d;
        k1 = (k1 % t + t) % t;
        m1 = a1 * k1 + m1;
        a1 = abs(a1 / d * a2);
    }
    if (no) printf("-1\n");
    else printf("%lld\n", (m1 % a1 + a1) % a1);
    return 0;
}
