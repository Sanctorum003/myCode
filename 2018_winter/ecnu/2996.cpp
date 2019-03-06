#include <iostream>
#include <cstdio>
#include <cmath>
typedef long long ll;
using namespace std;

int main(void)
{
    int n;
    cin>>n;
    for(int i = 0; i < n;++i)
    {
        ll a,n;
        cin>>a>>n;
        cout<<"case #"<<i<<":"<<endl;
        ll res = 1;
        while(n--)
        {
            res *=a;
        }
        if(n == 0)
            res = 1;
        printf("%lld\n",res);
    }
    return 0;
}