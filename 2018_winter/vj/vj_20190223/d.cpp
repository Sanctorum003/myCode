#include <iostream>
#include <algorithm>
using namespace std;

string res = "Impossible";

void dfs(int a[],int index,int val)
{
    if(index == 4)
    {
        cout<<val<<endl;
        if(val == 23)
            res = "Possible";
        return;
    }
    dfs(a,index+1,val+=a[index]);
    dfs(a,index+1,val-=a[index]);
    dfs(a,index+1,val*=a[index]);

}

int main(void)
{
    int a[5];
    for(int i = 0; i < 5;++i)
        cin>>a[i];
    while(1)
    {
        if(!a[0] && !a[1] && !a[2] && !a[3] && !a[4])   break;
        res = "impossible";
        for(int i = 0 ; i < 5; ++i)
        {
            swap(a[0],a[i]);
            dfs(a,1,a[0]);
        }
        
        cout<<res<<endl;
        for(int i = 0; i < 5;++i)
            cin>>a[i];
    }
    
    
    return 0;
}