#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{   
    int n;
    cin>>n;
    int a[n+1];
    fill(a,a+n+1,1);
    int  k;
    cin>>k;
    for(int i =0; i < k ;++i)
    {
        int t;
        cin>>t;
        a[t] = 0;
    }

    if(a[2])
        a[2] = a[1]+1;
    if(a[3])
        a[3] = a[2]+a[1]+1;

    for(int i =4; i<=n;++i)
    {
        if(a[i] != 0)
        {
            a[i] = a[i-1]+a[i-2]+a[i-3];
        }

    }

    cout<<a[n]<<endl;

    return 0;
}