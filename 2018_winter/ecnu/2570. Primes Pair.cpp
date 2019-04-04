#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    int i;
    if(n == 1)  return false;
    for(i =2; i<=sqrt(n);++i)
    {
        if(n%i == 0)
            break;
    }
    
    if(i > sqrt(n))
        return true;
    else
        return false;
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    while(n--)
    {
        int m;
        cin>>m;
        int cnt = 0;
        for(int k = 1; k <= m; ++k)
            if(isPrime(k) && isPrime(m-k+1))
                cnt++;
        cout<<cnt<<endl;
    }
    
    return 0;
}