#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin>>a[i];
    
    int lo,hi;
    for(int i = 0; i<q; ++i)
    {
        cin>>lo>>hi;
        int temp[hi-lo+1];
        int cnt = 0;
        for(int i = lo; i<=hi;++i)
            temp[cnt++] = a[i];
        
        sort(temp,temp+hi-lo+1);//sort [start,end)
        cout<<temp[0]<<endl;
    }
    return 0;
}