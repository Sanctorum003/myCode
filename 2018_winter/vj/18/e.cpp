#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    //a_{n} = 1/2 * n^{2} - 1/2 *n + 1; 第n个1所在的位置a_{n}
    //倒推出 n = ... 如果是n是整数则此位置为1

    ios::sync_with_stdio(false);
    cin.tie(0);
    //https://blog.csdn.net/iewlhf/article/details/51534183

    ll n;
    cin>>n;
    while(n--)
    {
        ll t;
        cin>>t;

        double x = (1+sqrt(1-8*(1-t)))/2;
        if(x - ll(x) == 0)
            cout<<1<<endl;
        else
            cout<<0<<endl;
        
    }
    return 0;
}
