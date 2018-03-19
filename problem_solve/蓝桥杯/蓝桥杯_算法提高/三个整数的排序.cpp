#include <iostream>
#include <algorithm>
using namespace std;

int comp(int a,int b)
{
    return a>b;
}

int a[3];

int main(void)
{
    for(int i = 0; i <3; ++i)
        cin>>a[i];

    sort(a,a+3,comp);

    for(int i = 0;i <3;++i)
        cout<<a[i]<<" ";

    return 0;
}