#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    int i =0;
    for(i = 2; i<=sqrt(n);++i)
    {
        if(n % i == 0 ) break;
    }

    if(i > sqrt(n))    return true;
    return false;
}

int main(void)
{
    int n;
    cin>>n;

    long long int sum = 1;
    int cnt = 0;
    int num = 2;

    while(1)
    {
        if(isPrime(num++))
        {
            // cout<<"prime:"<<num-1<<endl;
            sum *= num-1;
            cnt++;
        }

        if(cnt >= n)    break;
    }

    cout<<sum%50000<<endl;

    return 0;
}