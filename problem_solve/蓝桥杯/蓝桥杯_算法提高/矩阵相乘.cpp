#include <iostream>
using namespace std;

int a[1000][1000] = {0};
int b[1000][1000] = {0};
int c[1000][1000] = {0};

int main(void)
{
    int ai, aj;
    cin >> ai >> aj;

    for (int i = 0; i < ai; ++i)
    {
        for (int j = 0; j < aj; ++j)
        {
            cin >> a[i][j];
        }
    }

    int bi, bj;
    cin >> bi >> bj;
    
    for (int i = 0; i < bi; ++i)
    {
        for (int j = 0; j < bj; ++j)
        {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < ai; ++i)
    {
        for (int j = 0; j < bj; ++j)
        {
            for (int k = 0; k < aj; ++k)
            { //相乘
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (int i = 0; i < ai; ++i)
    {
        for (int j = 0; j < bj; ++j)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
