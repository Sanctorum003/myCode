# 1002
> 1) string 和 int 的数字转换 差 48；所有相关判断都要 str-48

> 2) s.size() 范围uint 循环时必须强制转换为 int

> 3) c++11 以上 int->string std::to_string() [华师可以c++17]

# 1008
> 1) reverse 用于数组时注意 Reverses the order of the elements in the range [first,last).

> 2)end() 函数返回一个指向当前vector末尾元素的下一位置的迭代器.要访问末尾元素,需要先将此迭代器减1。  
>   back() 函数返回当前vector最末一个元素的引用。

# 1009
>1) while(cin>>t)

# 1017
>1) 大数除法

# 1019
```cpp
printf("%010d", n);
//即其中10表示宽度，0表示前面添充0。
sort(v.begin(),v.end(),cmp);
//sort用法
```

# 1024
```cpp
//模板函数：将string类型变量转换为常用的数值类型（此方法具有普遍适用性）  
#include <sstream>  
template <class Type>  
Type stringToNum(const string& str)  
{  
    istringstream iss(str);  
    Type num;  
    iss >> num;  
    return num;      
}  
```


#1031
```
#include <cctype>

 if(!isdigit(string[j]))//判断是否是数字
```

# 1036
```cpp
//C语言中实现四舍五入: 
a = (int)(a+0.5)
// 注意负数的情况,把 + 换成 - 即可
```

# 1086
> 1) vector
> 2) reverse(v.begin(),v.end());

# 1091
> 1) pow(a,b) -> a^b 返回值为double