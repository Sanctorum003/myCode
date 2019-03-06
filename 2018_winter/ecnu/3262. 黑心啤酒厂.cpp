#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll x,ll y)
{
    return y==0?x:gcd(y,x%y);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x,n;
    cin>>x>>n;
    for(ll i = 2; i<=n; ++i)
    {
        ll m = gcd(x,i);//x和n的最小公倍数就是最少要喝的杯数
        ll gbs = x*i/m;
        cout<<gbs/x<<endl;
    }

    return 0;
}