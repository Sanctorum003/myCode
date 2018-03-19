#include <iostream>
using namespace std;

int func(int n,int k)
{
    if(k == 0 || k == n)    return 1;
    return func(n-1,k)+func(n-1,k-1);
}

int main(void)
{
    int n;
    int k;
    cin>>k>>n;

    cout<<func(n,k)<<endl;
    return 0;
}