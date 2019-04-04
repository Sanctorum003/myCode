#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    
    sort(a,a+n);
    
    int m;
    cin>>m;
    while(m--)
    {
        int t;
        cin>>t;
        cout<<a[t-1]<<endl;
    }
    
    return 0;
}