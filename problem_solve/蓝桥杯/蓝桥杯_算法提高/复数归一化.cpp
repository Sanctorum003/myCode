#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    double a;
    double b;
    cin>>a>>b;

    double resA;
    double resB;

    resA = a / sqrt(pow(a,2)+pow(b,2));
    resB = b / sqrt(pow(a,2)+pow(b,2));

    cout<<resA<<"+"<<resB<<"i"<<endl;


    return 0;
}