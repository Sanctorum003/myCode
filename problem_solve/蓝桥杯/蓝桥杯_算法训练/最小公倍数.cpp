#include <iostream>
using namespace std;

int main(void)
{
    int a;
    int b;
    cin>>a>>b;

    int m = a;
    int n = b;
    int r = 0;

    do
    {
        r = m % n;
        m = n;
        n = r;
    }while( n != 0);

    int res = a*b/m;

    cout<< res <<endl;

    return 0;
}