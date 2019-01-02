#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
    int num;
    cin>>num;
    int n;
    int a[5]={0};
    bool flag[5] = {0};
    int a1 = 1;
    int cnt3 = 0;
    while(cin>>n)
    {
        int t = n % 5;
        if(t == 0)
        {
            if(n%2 == 0)
            {
                flag[0] = true;
                a[0] += n; 
            }
        }
        else if(t == 1)
        {
            flag[1] = true;
            a[1] += a1*n;
            a1*=-1;
        }
        else if(t == 2)
        {
            flag[2] = true;
            a[2]++;
        }
        else if(t == 3)
        {
            flag[3] = true;
            a[3] += n;
            cnt3++;
        }
        else if(t == 4)
        {
            flag[4] = true;
            a[4] = n>a[4]?n:a[4];
        }
    }

    for(int i = 0 ; i < 5; ++i)
    {
        if(flag[i])
        {
            if(i == 3)
            {
                printf("%.1f",(double)a[3]/cnt3);
            }
            else
            {
                cout<<a[i];
            }
        }
        else
        {
            cout<<"N";
        }

        if(i != 4)
            cout<<" ";
    }
    return 0;
}