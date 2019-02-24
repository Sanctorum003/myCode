#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void)
{
    int m;
    int n;
    cin>>m>>n;
    char a[m][n];
    for(int i = 0; i < m; ++i)
        for(int j = 0; j <n; ++j)
            cin>>a[i][j];
    int num[n];
    fill(num,num+n,0);
    for(int i = 0; i < m; ++i)
        for(int j = 0; j <n; ++j)
        {
            if(a[i][j] == 'a')
            {
                num[j]++;
            }
            else if(a[i][j] == '#')
            {
                num[j] = 0;
            }
            else if(a[i][j] == '.')
            {
                // cout<<i-num[j]<<" "<<i<<" "<<j<<endl;
                if(num[j]>0)
                    a[i][j] = 'a';
                    a[i-num[j]][j] = '.';
            }
        }

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j <n; ++j)
            cout<<a[i][j];
        cout<<endl;
    }
    return 0;
}