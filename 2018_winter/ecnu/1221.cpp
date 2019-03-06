#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;
    cin>>n;
    bool zb[31];
    fill(zb,zb+31,false);
    while(n--)
    {
        while(1)
        {
            int t;
            cin>>t;
            if( t == -1) break;
            zb[t] = true;
        }
    }
    
    int i =1;
    for( i =1 ; i<=30;++i)
    {
        if(zb[i] == false)
            break;
    }
    
    if(i > 30)  cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    
    return 0;
}