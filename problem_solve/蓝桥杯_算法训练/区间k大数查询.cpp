#include <iostream>
#include <algorithm>
using namespace std;

int comp(int a,int b)
{
    return a>b;
}

int main(void)
{
    int n;
    cin>>n;
    int *a = new int(n);
    for(int i =0; i < n; ++i)
        cin>>a[i];
    int m;
    cin>>m;
    int l,r,k;
    while(m--)
    {
        cin>>l>>r>>k;
        int *p = new int(r-l+1);
        for(int i = 0; i <r-l+1;++i)
        {
            p[i] = a[l-1+i];
            cout<<p[i]<<" ";
        }
        // int *p = a+l-1;
        sort(p,p+(r-l+1),comp);
        cout<<p[k - 1]<<endl;
    }
    return 0;
}