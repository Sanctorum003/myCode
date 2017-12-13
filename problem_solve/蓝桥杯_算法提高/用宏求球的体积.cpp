#include <iostream>
using namespace std;
#define PI 3.1415926
#define V(r) (4.0/3.0)*PI*r*r*r

int main(void)
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);
    double r;
    cin>>r;
    cout<<V(r)<<endl;
    return 0;
}