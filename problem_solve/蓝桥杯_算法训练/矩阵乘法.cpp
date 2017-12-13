#include <iostream>
using namespace std;
int a[500][500];
int b[500][500];
int c[500][500];

int main(void)
{
    int m,s,n;
    cin>>m>>s>>n;

    // a[m*s]
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < s; ++j)
            cin>>a[i][j];

    for(int i = 0; i < s; ++i)
        for(int j = 0; j < n; ++j)
            cin>>b[i][j];

    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n;++j)
            for(int k = 0; k < s;++k)
            {
                c[i][j] += a[i][k] * b[k][j];
            }

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
            cout<<c[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}