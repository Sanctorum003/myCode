#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int m,n;
    cin>>m>>n;
    n = n % m;
    int a[m] = {0};
    for(int i = 0; i < m;++i)
        cin>>a[i];
    reverse(a,a+m-n);
    reverse(a+m-n,a+m);
    reverse(a,a+m);
    for(int i = 0; i < m;++i)
    {
        cout<<a[i];
        if(i != m-1)    cout<<" ";
    }
    cout<<endl;
    return 0;
}