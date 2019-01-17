#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin>>n;
    int a[n+1] = {0};
    int cnt = 0;
    while(n--)
    {
        int t;
        int flag = true;
        cin>>t;

        int min = 1;
        int minval = 0x3f3f3f3f;
        for(int i = 1 ; i <= cnt; ++i)
        {
            if( a[i] - t <= minval &&  a[i] - t >= 0)
            {
                minval = a[i] - t;
                min = i;
                flag = false;
            } 
        }

        if(flag)
            a[++cnt] = t;
        else
            a[min] = t;

        // for(int i = 1 ; i <= cnt ;++ i)
        //     cout<<a[i]<<" ";
        // cout<<endl;
        

    }



    cout<<cnt<<endl;

    return 0;
}