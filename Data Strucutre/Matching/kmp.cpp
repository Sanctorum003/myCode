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
        }
        else
            k = next[k]; //不匹配则利用已有next数组回溯
    }
}

int KMP(char str[], int str_len,char sub[],int sub_len,int next[],int pos)
{
    //sub 在 str 中 从第pos位置开始是否匹配
    int i = pos;//用于str
    int j = 0;// 用于sub
    while(i < str_len && j < sub_len)
    {
        if(j == -1 || str[i] == sub[j]) //目前全不匹配到下一位开始重新开始匹配 || 当前字符匹配
        {
            ++i;++j;
        }
        else
        {
            j = next[j]; // sub用next回溯
        }
    }

    if( sub_len = j )//说明完全匹配
        return i - sub_len; // 找到匹配的位置
    else //否侧不匹配
        return -1;
}

int main(void)
{
    char s[] = {'a','b','c','a','b','a','a','a','b','a','a','b','c','a','c'};
    char t[] = {'a','b','a','a','b','c','a','c'};
    int next[13]={0};
    get_Next(s,13,next);
    cout<<endl;
    for(int i=0;i<13;++i)
        cout<<next[i]<<" ";
    cout<<endl;
    cout<<KMP(s,13,t,5,next,0)<<endl;
    return 0;
}