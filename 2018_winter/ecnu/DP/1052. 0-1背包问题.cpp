#include <iostream>
#include <algorithm>
using namespace std;

/*
f[i][v]=max{f[i-1][v],f[i-1][v-c[i]]+w[i]} 
即f[i][v]表示前i件物品恰放入一个容量为v的背包可以获得的最大价值。
*/

int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int n,M;
        cin>>n>>M;
        int dp[M+1];
        int weight[n+1];
        int value[n+1];
        fill(dp,dp+M+1,0);
        fill(weight,weight+n+1,0);
        fill(value,value+n+1,0);
        for(int i =1 ; i<=n ;++i)
            cin>>weight[i]>>value[i];
        
        for(int i = 1; i <=n; ++i)//加入前i件物品
            for(int j = M; j>=weight[i];--j)//从后向前 依次判断是否需要加第i件物品
                dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);

        cout<<dp[M]<<endl;


    }

    return 0;
}