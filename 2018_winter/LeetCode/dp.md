# 322. 零钱兑换
https://leetcode-cn.com/problems/coin-change/  
关键点 建立状态存储数组 找转移方程
1) 建立什么数组?数组中保存什么?
2) 如何找状态转移方程?

**猜想**：数组中保存的是答案
> 此题中就是找零的最少硬币  
> 建立dp[num+1]为0~num元的最少硬币数  
> 初始值需要用于最后判断是否能相应的组合。为num+1  

**转移方程**：这样思考。在所给例子中dp[11]的最小值为min(dp[11-5]+1,dp[11-2]+1,dp[11-1]+1,dp[11])这样就能用到之前保存的状态，且dp[11] = dp[11]时即为无法找零。  

```cpp
for(int i = 1 ; i < num ; ++i)
    for(int j = 0 ; j < coins.size() ; ++j)
        dp[i] = min(dp[i],dp[i-coins[j]]+1);
```

```cpp
//数组初始化
#include <algorithm>
void fill (ForwardIterator first, ForwardIterator last, const T& val);
```