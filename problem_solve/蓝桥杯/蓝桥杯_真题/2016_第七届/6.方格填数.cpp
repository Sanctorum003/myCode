#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int cnt = 0;
    do{
        if(abs(a[0]-a[1]) != 1 &&
           abs(a[1]-a[2]) != 1 &&
           abs(a[3]-a[4]) != 1 &&
           abs(a[4]-a[5]) != 1 &&
           abs(a[5]-a[6]) != 1 &&
           abs(a[7]-a[8]) != 1 &&
           abs(a[8]-a[9]) != 1 &&
           abs(a[3]-a[7]) != 1 &&
           abs(a[0]-a[4]) != 1 &&
           abs(a[4]-a[8]) != 1 &&
           abs(a[1]-a[5]) != 1 &&
           abs(a[5]-a[9]) != 1 &&
           abs(a[2]-a[6]) != 1 &&
           abs(a[0]-a[3]) != 1 &&
           abs(a[1]-a[4]) != 1 &&
           abs(a[4]-a[7]) != 1 &&
           abs(a[2]-a[5]) != 1 &&
           abs(a[5]-a[8]) != 1 &&
           abs(a[6]-a[9]) != 1 &&
           abs(a[1]-a[6]) != 1 &&
           abs(a[0]-a[5]) != 1 &&
           abs(a[4]-a[9]) != 1 &&
           abs(a[3]-a[8]) != 1 )
           //  0 1 2
           //3 4 5 6
           //7 8 9 

            cnt++;
    }while(next_permutation(a,a+10));

    cout<<cnt<<endl;
    return 0;
}