#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main(void)
{
    int cnt = 0;
    int a[9] = {1,2,3,4,5,6,7,8,9};
    do
    {
        if(a[0] + ((double)a[1]/(double)a[2]) + ((double)(a[3]*100+a[4]*10+a[5]*1)/(double)(a[6]*100+a[7]*10+a[8]*1)) == 10)
        {
            cnt++;
        }
    }while(next_permutation(a,a+9));

    cout<<cnt<<endl;

    return 0;
}