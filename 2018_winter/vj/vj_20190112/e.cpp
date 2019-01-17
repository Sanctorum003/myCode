#include <iostream>
using namespace std;

int main(void)
{
    int m,n;//m people n food
    cin>>m>>n;
    int a[n+1] = {0};//饭友
    int b[m+1] = {0};//每人对应的号
    for(int i = 1 ; i <= m ;++i)
    {
        int t;
        cin>>t;
        a[t]++;
        b[i] = t;
    }

    for(int i = 1 ; i <= m; ++i)
    {
        // cout<<a[i]<<" "<<b[i]<<endl;
        if(a[b[i]]-1 > 0)
            cout<<a[b[i]]-1<<endl;
        else/* code */
            cout<<"BeiJu"<<endl;
        
        
    }
    return 0;
}