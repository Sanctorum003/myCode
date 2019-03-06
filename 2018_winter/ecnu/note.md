# 2853
```cpp
#include <string>
getline(cin,string);
```
* 判断闰年
```cpp
 if((year%4==0 && year%100!=0)||year%400==0){
    printf ("%i is a leap year!",year);
}else{
    printf ("%i is not a leap year!",year);
}
```