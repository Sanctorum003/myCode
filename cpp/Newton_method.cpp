#include <iostream>
#include <cmath>
using namespace std;

double nsqrt(double a)
{
    double err = 1e-6;
    double res = 0x5f3759df;
    while(fabs(res - a/res ) > err)
    {
        res = (res + (a/res))/2;
    }

    return res;
}

int main(void)
{
    while(1)
    {
        double n;
        cin>>n;
        cout<<nsqrt(n)<<endl;
    }
    return 0;
}

