/***
 * 因为要考虑负数，所以先排序
 * 每次比较首部两个数和结尾两个数的大小。谁大取谁，（通过两个两个取，可以消除负数的影响）
 * 如果要取的还剩1个，取最后一个数（最大的那个）
 ***/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
    int cnt;
    cin>>cnt;
    while(cnt--)
    {
        int p,q;
        cin>>p>>q;
        int a[p]={0};
        for(int i = 0; i<p;++i)
            cin>>a[i];
        // for(int i = 0; i<p;++i)
        //     cout<<a[i];
        sort(a,a+p);
        int m = 0;
        int n = p-1;
        int sum = 1;
        while(m <= n && q > 0)
        {
            if((a[m] * a[m+1] > a[n]*a[n-1]) && q >= 2)
            {
                sum *=(a[m] * a[m+1]);
                m += 2;
                q -= 2;
            }
            else
            {
                sum *=a[n];
                n -= 1;
                q -= 1;
            }
            // cout<<sum<<endl;
        }

        cout<<sum<<endl;
    }   
    return 0;
}//-2 -1 1 2 3
