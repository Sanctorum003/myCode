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
        ll a;
        cin>>a;
        cout<<"case #"<<i<<":"<<endl;
        ll res = pow(2,a);
        printf("%lld\n",res);
    }
    return 0;
}