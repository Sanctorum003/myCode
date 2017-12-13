#include <iostream>
#include <algorithm>
using namespace std;
int C;//背包容量
int M;//物品总数量
int dp[1001];//数组
int w[101];//物品重量
int v[101];//物品价值
int cnt;

int main(void)
{
    cin>>M>>C; 
    int W;//物品重量
    int V;//物品价值
    int N;//单个物品数量
    for(int i = 1; i <=M ;++i)
    {
        cin>>W>>V>>N;
        for(int j = 1;;j*=2)
        {
            if( N > j)
            {
                cnt++;
                w[cnt] = W*j;
                v[cnt] = V*j;
                N -= j;
            }
            else
            {
                cnt++;
                w[cnt] = W*j;
                v[cnt] = V*j; 
                break;
            }
        }
    }//初始化+划分物品 = 转换成01背包

    for(int i = 1 ; i<= cnt; ++i)
    {
        for(int j = C; j>=w[i]; --j)
        {
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }

    cout<<dp[C];

    return 0;
}
