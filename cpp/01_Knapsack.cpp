#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int w[6] = {0,2,2,6,5,4};//待加入的物体重量
    int v[6] = {0,6,3,5,4,6};//待加入的物体价值

    // 二维数组实现
    // int f[6][11] = {0};//dp数组
    // for(int j = 1; j <= 10; ++j)
    // {//背包容量由1到10
    //     for(int i = 1; i <= 5; ++i)
    //     {//背包从物品1开始加到物品5
    //         if(w[i] > j)    
    //             f[i][j]=0;
    //         else
    //             f[i][j] = max(f[i-1][j],f[i-1][j-w[i]]+v[i]);
    //     }
    // }

    //一位数组实现
    int f[11] = {0};//dp数组
    for(int i =1; i <6;++i)
    {
        for(int j = 10; j >= w[i]; --j)
        {
            f[j] = max(f[j],f[j-w[i]]+v[i]);//逐层更新
        }
    }

    cout<<"answer:"<<f[10]<<endl;
    return 0;
}