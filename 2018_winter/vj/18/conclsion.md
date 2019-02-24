# 3532. 热河路
https://acm.ecnu.edu.cn/problem/3532/

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    //a_{n} = 1/2 * n^{2} - 1/2 *n + 1; 第n个1所在的位置a_{n}
    //倒推出 n = ... 如果是n是整数则此位置为1

    ios::sync_with_stdio(false);
    cin.tie(0);
    //使得cin的速度变快
    //https://blog.csdn.net/iewlhf/article/details/51534183

    ll n;
    cin>>n;
    while(n--)
    {
        ll t;
        cin>>t;

        double x = (1+sqrt(1-8*(1-t)))/2;
        if(x - ll(x) == 0)//判断是整数
            cout<<1<<endl;
        else
            cout<<0<<endl;
        
    }
    return 0;
}
```

# 3530. 和你在一起
* 两个字符串自左向右逐个字符相比（按ASCII值大小相比较），直到出现不同的字符或遇’\0’为止。当两个数的位数一样，则直接可以应用字符串的比较。

string与数值之间的转换  
http://www.jyguagua.com/?p=2347
> 标准库中定义了to_string(val);可以将其它类型转换为string。还定义了一组stoi(s,p,b)、stol(s,p,b)、stod(s,p,b)等转换函数，可以函数，可以分别转化成int、long、double等.