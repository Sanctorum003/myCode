#include <iostream>
using namespace std;

#define w a
#define v b
#define INF 0x3f3f3f3f

int a[101];
int b[101];
int dp[201][200001];

int main(void)
{
    int n;//数对 个数
    cin>>n;
    int entireW = 0 ;

    for(int i=1 ; i <=n; ++i)
    {
        cin>>a[i]>>b[i];
    }

    int sum = 0;
    for(int i = 1; i <= n;++i)
        sum+=a[i];

    entireW = sum + 100000;
    // cout<<entireW<<endl;
    // 3719

    for(int i = 1; i < n; ++i)
        for(int j = 1; j < 200001; ++j)
            a[i][j] = -INF;

    


    for(int i= 1; i<=n; ++i)
    {
        for(int j = entireW ; j>=w[i] + 1000 ; --j )
        {
            if(dp[j-(w[i]+1000)]+v[i] > dp[j])
            {
                dp[j] = dp[j-(w[i]+1000)]+v[i];
                as[j] = as[j]+w[i];
            }
            cout<<dp[entireW]<<" "<<as[entireW]<<endl;
        }
    }


    
    return 0;
}

/*
5
-403 -625
-847 901
-624 -708
-293 413
886 709
*/