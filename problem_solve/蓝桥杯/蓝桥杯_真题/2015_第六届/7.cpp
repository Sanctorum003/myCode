#include <iostream>
using namespace std;

int sum;
int ans;

void dfs(int n)
{
    if(sum > 13) return;
    if(n == 14)
    {
        if(sum == 13)
            ans++;
    }
    else
    {
        for(int i = 0 ; i < 5;++i)
        {
            sum += i;
            dfs(n+1);
            sum -= i;
        }
    }

}

int main(void)
{//52 13
    sum = 0;
    ans = 0;
    dfs(1);
    cout<<ans<<endl;
    return 0;
}