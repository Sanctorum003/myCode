#include <iostream>
using namespace std;

int sum(int n )
{
    int s = 0;
    for(int i = 1 ; i <= n ; ++i)
    {
        s += i;
    }

    return s;
}

int main(void)
{
    int n = 0;
    cin>>n;
    int ssum = 0;
    for(int i = 1; i<=n; ++i)
    {
        ssum += sum(i);
    }

    cout<<ssum<<endl;
    return 0;
}