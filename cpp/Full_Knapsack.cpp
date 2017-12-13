#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int w[6] = {0,2,2,6,5,4};//待加入的物体重量
    int v[6] = {0,6,3,5,4,6};//待加入的物体价值
    int f[11] = {0};//dp数组

    for(int i = 1; i <= 5 ; ++i)
    {
        for(int j = w[i]; j <= 10;++j)
        {
            f[j] = max(f[j],f[j-w[i]]+v[i]);
        }
    }

    cout<<"answer:"<<f[10]<<endl;

    return 0;
}