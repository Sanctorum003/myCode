#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.1415926

int main(void)
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);
    double n;
    cin>>n;
    double a = -PI;
    double b = PI;
    double mid = (a+b)/2;
    while(fabs(n-cos(mid))>1e-12)
    {
        if(cos(mid) >= n)
            a = mid;
        else
            b = mid;
        mid = (a+b)/2;
    }

    cout<<mid<<endl;
    
    return 0;
}