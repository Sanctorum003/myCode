#include <iostream>
#include <cstring>
using namespace std;

#define max(a,b) a>b?a:b

int dp[2000][2000];

int main()
{
    int n;
    cin>>n;
    string a,b;
    while(n--)
    {
        cin>>a>>b;
        memset(dp,0,sizeof(dp));
        for(int i = 1; i<=a.size();++i)
            for(int j = 1; j<=b.size();++j)
            {
                if(a[i-1] == b[j-1])//从第0个字符开始匹配
                    dp[i][j] = dp[i-1][j-1] +1;
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        cout<<dp[a.size()][b.size()]<<endl;
    }
    

    return 0;
}


