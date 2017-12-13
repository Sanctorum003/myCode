#include <iostream>
#include <algorithm>

using namespace std;

int comp(int a,int b)
{
    return a>b;
}

int main(void)
{
    long long int a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3,comp);
    for(int i = 0; i < 3;++i)
        cout<<a[i]<<" ";
}