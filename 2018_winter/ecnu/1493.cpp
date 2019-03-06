#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main(void)
{
    ll a;
    cin>>a;
    ll res = sqrt(a);
    if(res*res < a)
        res+=1;
    cout<<res<<endl;
    return 0;
}