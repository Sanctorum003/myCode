#include <stdio.h>  
#include <string.h>  
/*
题目没有难度，唯一可能的是有的同学也许不知道%*s是什么意思。
容易联想到指针。回想一下，int*a可以是表示不定长得到a数组。
那么这里的%*s也是类似，这里需要传2个参数，第一个参数是%s的个数(注意不是长度)，第二个参数就是%s。
需要写的部分是buf的位置，buf左边和右边都是空格。
*/
void StringInGrid(int width, int height, const char* s)  
{  
    int i,k;  
    char buf[1000];  
    strcpy(buf, s);  
    if(strlen(s)>width-2) buf[width-2]=0;  
  
    printf("+");  
    for(i=0; i<width-2; i++) printf("-");  
    printf("+\n");  
  
    for(k=1; k<(height-1)/2; k++)  
    {  
        printf("|");  
        for(i=0; i<width-2; i++) printf(" ");  
        printf("|\n");  
    }  
  
    printf("|");  
  
    printf("%*s%s%*s", (width-(int)strlen(s)-2)/2,"",s,(width-(int)strlen(s)-1)/2,"");  
  
    printf("|\n");  
  
    for(k=(height-1)/2+1; k<height-1; k++)  
    {  
        printf("|");  
        for(i=0; i<width-2; i++) printf(" ");  
        printf("|\n");  
    }  
  
    printf("+");  
    for(i=0; i<width-2; i++) printf("-");  
    printf("+\n");  
}  
  
int main()  
{  
    StringInGrid(3,6,"abcd1234");  
    return 0;  
}  