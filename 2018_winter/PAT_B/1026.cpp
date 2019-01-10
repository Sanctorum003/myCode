#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
    long int a,b;
    cin>>a>>b;
    long int minus,res;
    double tim;
    minus = b - a;
    tim = (double)minus/ 100;
    res = (int)(tim+0.5);
    // cout<<minus<<" "<<res<<" "<<tim<<endl;
    int hour = res / 3600;
    int min = res % 3600 / 60;
    int sec = res % 60;
    printf("%02d:%02d:%02d",hour,min,sec);
    return 0;
}
