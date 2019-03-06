#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int main(void)
{   
    int n;
    cin>>n;
    while(n--)
    {
        int num;
        cin>>num;
        int a[num];
        for(int i =0; i < num;++i)
            cin>>a[i];
        int dp[num+1];
        int res= INT_MIN;
        fill(dp,dp+num+1,0);
        for(int i = 1; i <= num;++i)
        {
            if(a[i] > a[i-1])
                dp[i] = dp[i-1]+
        }

    }

    return 0;
}
//1 8 