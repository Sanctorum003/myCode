#include <iostream>
#include <cstring>
using namespace std;

bool isLoop(int a[],int n)
{
    int tmp = a[0];
    for(int i = 0; i<n;++i)
    {
        if(a[i] != tmp)
            return true;
    }

    return false;
}

int main(void)
{
    int n;//小朋友个数
    cin>>n;
    int a[n];//每个小朋友糖果个数
    int b[n] ={0};//temp;
    int cnt  = 0;//多发糖个数
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i = 0; i < n; ++i)
        cin>>a[i];

    while(isLoop(a,n))
    {
        for(int i = 0 ; i < n; ++i)
        {    
            a[i] /=2;
            b[i] = a[i]; //每个小朋友拿出的糖果
            
        }

        for(int i = 0; i<n; ++i)
            cout<<b[i]<<" ";
        cout<<endl;

        //b 1 1 2
        //a 1 1 2
        //a 2 3 3
        //a 2 4 4

        for(int i = n-1; i >= 0 ; --i)
        {
            if(i != 0)
                a[i-1] += b[i];
            else
                a[n-1] += b[0];
        }
            
        for(int i=0; i < n ; ++i)
            if(a[i] % 2 == 1)
            {
                cnt++;
                a[i]++;
            }

        // for(int i = 0; i<n; ++i)
        //     cout<<a[i]<<" ";
        // cout<<endl;
    }

    cout<<cnt<<endl;
    //2 2 4  1 1 2
    //       1 2 1
    //2 3 3
    //2 4 4 +2 1 2 2
    //         2 2 1
    //3 4 3
    //4 4 4 +2


    return 0;
}