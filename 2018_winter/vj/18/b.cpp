#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n;
    cin>>n;
    vector<vector<int>> a(n+1,vector<int>(n+1,1));
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <=i;++j)
        {
            if(j!= 1 && j != i)
            {
                a[i][j] = a[i-1][j-1]+a[i-1][j];
            }
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <=i;++j)
        {
            cout<<a[i][j];
            if(j!= i)
                cout<<" ";
        }
        if(i != n)
            cout<<endl;
    }

    return 0;
}