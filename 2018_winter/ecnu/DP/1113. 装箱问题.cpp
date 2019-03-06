#include <iostream>
#include <algorithm>
using namespace std;

/*
变种的0-1背包
 vol[j] = max(vol[j],vol[j-a[i]]+a[i]);
把价值等同于体积的0-1背包
*/

int main(void)
{
    int v;
    int n;
    while(cin>>v>>n)
    {
        int vol[v+1];
        int a[n+1];
        fill(a,a+n+1,0);
        fill(vol,vol+v+1,0);
        for(int i = 1; i <= n; ++i)
        {
            cin>>a[i];
        }
        
        for(int i = 1; i <= n;++i)
        {
            for(int j = v; j>=a[i];--j)
            {   
                vol[j] = max(vol[j],vol[j-a[i]]+a[i]);
            }
        }      
        cout<<v-vol[v]<<endl;
    }

    return 0;
}