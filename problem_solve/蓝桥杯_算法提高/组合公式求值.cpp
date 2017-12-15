#include <iostream>
#include <cmath>
#define LL long long
using namespace std;

LL fact(LL n)
{
    if(n <= 1) return 1;
    else return n*fact(n-1);
}

LL C(LL m,LL n)
{
    LL tmp = 0;
    tmp = fact(n);
    tmp /= fact(n-m);
    tmp /= fact(m);
    return tmp;
}


int main(void)
{
    LL n,m;
    cin>>n>>m;
    int sum = 0;
    for(int i = 0; i <= n; ++i)
    {
        sum += C(m,n)*C(i,n)*pow(i,3);
    }
    
    cout<<sum%987654321<<endl;

    return 0;
}