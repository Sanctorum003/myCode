# 1. 两数之和
## 利用map或unordered_map
```cpp
#include <map>
#include <unordered_map>

map<int,int> m; //定义
m[key] = val; //赋值1
m.insert ( std::pair<char,int>('a',100) );//赋值2
m.find(key)//找到key在m的位置
m.count(key)//是否存在key
```
> 注意：使用insert()插入元素的方式并不能覆盖掉相同key的值；而使用[]方式则可以覆盖掉之前的值。

## 本题的方法就利用map
> 一遍遍历将元素和位置利用map关联起来
> 第二遍 查看 target - nums[i] 在map中是否存在位置。并且注意nums[i]!=i

# 35. 搜索插入位置
```cpp
it = find(begin(),end(),val);
//iterator 转 int
std::distance(begin(),it);
```