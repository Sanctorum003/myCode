#include <iostream>
#include <climits>
using namespace std;

int main(void)
{   
    int n,m;
    cin>>n>>m;
    int res = 0;
    int a[n][m];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin>>a[i][j];
    
    for(int i = 0; i < n; ++i)
    {
        int t = INT_MIN;
        for(int j = 0; j < m; ++j)
        {
            t = a[i][j] > t ? a[i][j] :t;
        }
        res+=t;
    }

    cout<<res<<endl;

    return 0;
}