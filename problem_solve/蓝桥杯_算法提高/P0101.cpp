#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    double n;
    cin>>n;

    printf("%E\n",(n*950)/(3*pow(10,-23)));//注意E使用大写

    return 0;
}