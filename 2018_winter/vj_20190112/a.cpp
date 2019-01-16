#include <iostream>
using namespace std;

bool isPrime(int n)
{
    int i = 0;
    for(i = 2 ; i < n;++i)
    {
        if(n % i == 0) break;
    }

    if(i >= n) return true;
    else return false;
}

int main(void)
{
    int a;
    cin>>a;

    int b = a/2;
    int c = a-a/2;

    while(!isPrime(b) || !isPrime(c))
    {
        b--;
        c++;
    }

    // cout<<b<<" "<<c<<endl;
    cout<<b*c<<endl;

    return 0;
}