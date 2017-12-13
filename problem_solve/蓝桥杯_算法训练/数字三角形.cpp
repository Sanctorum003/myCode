#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[111][111];
int dp[111][111];


int main(void)
{
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= i; ++j)
            cin>>a[i][j];
    }

    for(int i = 1 ; i <= n; ++i)
        dp[n][i] = a[n][i];

    for(int i = n-1; i > 0; --i)
    {
        for(int j= 1; j<= i ;++j)
        {
            dp[i][j] = a[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
        }
    }

    //   for(int i = 1; i <= n; ++i)
    // {
    //     for(int j= 1; j<= i ;++j)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

        cout<<dp[1][1]<<endl;
    return 0;
}