#include <iostream>
using namespace std;

 char a[1000][26];

int main(void)
{
    int r;  //row
    int c;  //column
    int ch; //char
    cin >> r;
    cin >> c;
    for (int i = 0; i < r; ++i)
    {
        int ch = 'A';
        for (int j = i; j < c; ++j)
            a[i][j] = ch++;
        ch = 'A';
        for (int j = i-1; j >= 0; --j)
            a[i][j] = ++ch;
    }

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}