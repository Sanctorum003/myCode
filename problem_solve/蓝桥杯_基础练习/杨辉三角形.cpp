#include <iostream>
using namespace std;

int a[34][34];

int main(void)
{
    for(int i = 0; i < 34; ++i)
    {
        for(int j = 0; j <=i ; ++j)
        {
            if(j == 0)
                a[i][j] = 1;
            else if(j == i)
                a[i][j] = 1;
            else
                a[i][j] = a[i-1][j] + a[i-1][j-1];
        }
    }

    int n;
    cin>>n;

    for(int i = 0; i <n; ++i)
    {
        for(int j = 0; j <=i ; ++j)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}