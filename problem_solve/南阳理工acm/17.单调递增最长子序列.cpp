// http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=17

#include <iostream>
#include <cstring>
using namespace std;

int getPos(int arr[],int len,int e)
{
    for(int i = 0; i <=len;++i)
    {
        if(arr[i] >= e)
            return i;
    }

    return 0;
}

int main(void)
{
    int n;
    int len = 0;
    cin>>n;
    int arr[10000] = {0};
    string a;
    while(n--)
    {
        len = 0;
        memset(arr,0,sizeof(arr)); 
        cin>>a;
        arr[0] = 0;
        for(int i = 0 ; i < a.size() ; ++i)
        {
            if(a[i] > arr[len])
            {
                arr[++len] = a[i];
            }
            else
            {
                int j = getPos(arr,len,a[i]);
                arr[j] = a[i];
            }

            // for(int k = 1; k<=len;++k)
            //     cout<<(char)arr[k]<<" ";
            // cout<<endl;
        }
       cout<<len<<endl;
       //abklmncdefg
       //a b c d e f
    }

    return 0;
}