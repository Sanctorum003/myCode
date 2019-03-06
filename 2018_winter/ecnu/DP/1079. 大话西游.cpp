#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int a[30][30];
    int n;
    cin>>n;
    while(n)
    {
        fill(a[0],a[0]+30*30,1);
        for(int i = 0; i < n; ++i)
        {
            for(int j =0; j <= i; ++j)
            {
                if(j != 0 && j != i)
                {
                    a[i][j] = a[i-1][j-1]+a[i-1][j];
                }
            }
        }

        for(int i = 0; i < n; ++i)
        {
            for(int j =0; j <= i; ++j)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        cin>>n;
    }
    return 0;
}