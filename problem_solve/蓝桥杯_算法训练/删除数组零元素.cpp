#include <iostream>
using namespace std;

int CompactIntegers(int n,int a[])
{
    int *t = new int(n);
    int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] != 0)
        {
            t[cnt++] = a[i];
        }
    }

    for(int i = 0; i < cnt; ++i)
    {
        a[i] = t[i];
    }
    return cnt;
}

int main(void)
{
    int n;
    cin>>n;
    if(n <= 0)
    {
        cout<<0<<endl;
        return 0;
    }
    int *a = new int(n);
    for(int i = 0;  i< n; ++i)
    {
        cin>>a[i];
    }

    int nn = CompactIntegers(n,a);

    cout<<nn<<endl;
    for(int i = 0 ; i < nn; ++i)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}