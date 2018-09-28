/***
 * 殷人昆书上的结果
 * next[j] = -1     (j=0)
 *         = k+1    (前k+1个串中 前缀等于后缀 的个数，k从0开始) 
 *         = 0      (其他情况)
 ***/
#include <iostream>
using namespace std;

void get_Next(char sub[], int len ,int next[])
{
    //相当于自己与自己匹配
    //方法是王道p270页上的手算方法
    int j = 0;//表达式中的 j
    int k = -1;//表达式中的 k
    next[0] = -1;
    while(j < len - 1) //len的时候是next[0~8],len-1的时候是next[0~7]
    {
        if(k == -1 || sub[j] == sub[k])
        {//如何j=-1 或者 匹配
            ++j;++k ;//向后继续匹配
            next[j] = k;// 第j项为k 
                         // 就是不匹配时 Next[j] = 0;
                         // 匹配时 Next[j] = k+1;
            cout<<j;
        }
        else
            k = next[k]; //不匹配则利用已有next数组回溯
    }
}


int main(void)
{
    char s[] = {'a','b','a','a','b','c','a','c'};
    int next[8]={0};
    get_Next(s,8,next);
    cout<<endl;
    for(int i=0;i<8;++i)
        cout<<next[i]<<" ";
    cout<<endl;
    return 0;
}