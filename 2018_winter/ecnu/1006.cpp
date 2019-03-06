#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if(n== 1) return false;
    int i;
    for(i = 2;i<n;++i)
    {
        if(n%i == 0)
            break;
    }
    
    if(i >= n) return true;
    else return false;
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a,b;
    while(cin>>a>>b)
    {
        int cnt =0;
        for(int i = a;i <=b;++i)
            if(isPrime(i))
                ++cnt;
        cout<<cnt<<endl;
    }
    
    return 0;
}
// 2 3 5 7 