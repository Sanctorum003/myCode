#include <iostream>
using namespace std;
// -127x + 97y = 1
// int exgcd(int a,int b,int &x,int &y)
// {
//     if(b == 0)
//     {
//         x = 1;
//         y = 0;
//         return a;
//     }
//     int r =  exgcd(b,a%b,x,y);
//     int t = x;
//     x = y;
//     y = t - a/b*y;
//     return r;
// }

// int gcd(int a,int b)
// {
//     return b ? gcd(b,a%b) : a ;
// }

// int main(void)
// {
//     int a = -127;
//     int b = 97;
//     int c = 1;
//     int x = 0;
//     int y = 0;
//     int d = exgcd(a,b,x,y);
//     cout<<x<<" "<<y<<" "<<d<<endl;
//     return 0;
// }

int main(void)
{
    for(int x = 0 ; x < 1000; ++x)
        for(int y = 0 ; y < 1000; ++y)
        {
            if(-127*x+97*y == 1)
            {
                cout<<x+y<<endl;
            }
        }

    return 0;
}