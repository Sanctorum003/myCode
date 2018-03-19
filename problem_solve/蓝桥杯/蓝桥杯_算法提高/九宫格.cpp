#include <iostream>
using namespace std;

int a[3][3];

int main(void)
{
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3;++j)
            cin>>a[i][j];
    
    if(a[0][0] == 4 &&
        a[0][1] == 9 &&
        a[0][2] == 2 &&
        a[1][0] == 3 &&
        a[1][1] == 5 &&
        a[1][2] == 7 &&
        a[2][0] == 8 &&
        a[2][1] == 1 &&
        a[2][2] == 6)
        cout<<1<<endl;
    else
        cout<<0<<endl;
    
    return 0;
}