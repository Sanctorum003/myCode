#include <iostream>
#include <cstring>
#include <vector>
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
    vector<int> v;
    int arr[10000] = {0};
    int temp;
    int n = 0;
    while(cin>>n)
    {
        v.clear();
        for(int i = 0 ; i < n; ++i)
        {
            cin>>temp;
            v.push_back(temp);
        }
        memset(arr,0,sizeof(arr));
        int len = 0;
        for(int i = 0 ; i < n ; ++i)
        {
            if(v[i] > arr[len])
                arr[++len] = v[i];
            else
            {
                int j = getPos(arr,len,v[i]);
                arr[j] = v[i];
            }
        }
        cout<<len<<endl;

    }
    return 0;
}