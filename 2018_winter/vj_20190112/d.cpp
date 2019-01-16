#include <iostream>
using namespace std;

int dfs(int x,int y,int n)
{

    int minval = 0x3f3f3f3f;
    if(x == y)
    {
        // cout<<x<<" "<<y<<" "<<n<<endl;
        return n;
    }

    if(x < y && x>= 0 && x <= 100000 )
    {// 
        if( x+1 < y && 2*x <y)
        {
            int a = dfs(2*x,y,n+1);
            minval = min(a,minval);
        }
        

        int b = dfs(x+1,y,n+1);
        // cout<<x<<" "<<y<<" "<<n<<endl;
        minval = min(b,minval);

        int min = 1;
        int minval = y-x;
        for(int i = 1 ; i <= y-x;++i)
        {
            
            if((x-i)*2 - x < minval)
            {
                min = i;
                minval = (x-i)*2 - x;
            }
        }
        int c = dfs((x-min)*2,y,n+min+1);
        // cout<<x<<" "<<y<<" "<<n<<endl
    }
    else if( x > y  && x>= 0 && x <= 100000 )
    {
        int a = dfs(x-1,y,n+1);
        // cout<<x<<" "<<y<<" "<<n<<endl;
        minval = min(a,minval);
    }


    return minval;
}


int main(void)
{
    int x, y;
    cin>>x>>y;
    int res = dfs(x,y,0);
    cout<<res<<endl;
    return 0;
}