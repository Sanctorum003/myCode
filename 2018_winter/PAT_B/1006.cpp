#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin>>n;
    int b = n / 100;
    int s = n % 100 / 10;
    int g = n % 10;
    int cnt = 0;
    while(b--)
        cout<<"B";
    while(s--)
        cout<<"S";
    while(g--)
        cout<<++cnt;
    cout<<endl;
    return 0;
}