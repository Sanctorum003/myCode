# 53. 最大子序和
```cpp
#include <limits.h>
INT_MAX
INT_MIN

//连续自序和，所以主要目标是找到里面所有子序列中最大的
int res = INT_MIN;
int curSum = 0; // 注意这里是0
curSum = max(curSum+nums[i],nums[i]);//加上当前位置的值，是否会变小。变小则重新计算curSum
res = max(res,curSum);.//取出最大的子序列
```
# 62、63 不同路径
```cpp
//二维dp 爬楼扩展
//每个位置初试为0 [0][0]为1
//对每个位置考察上方和左方是否可通（对于障碍跳过），
//通者，加上前一位置的条数
```

# 64. 最小路径和
```cpp
if(i == 0 && j == 0) dp[i][j] = grid[i][j];
else if(i == 0) dp[i][j] = dp[i][j-1] + grid[i][j];
else if(j == 0) dp[i][j] = dp[i-1][j] + grid[i][j];
else dp[i][j] = min(dp[i][j-1] + grid[i][j],dp[i-1][j] + grid[i][j]);
```

# 70. 爬楼梯
简单的dp
```cpp
dp[0] = 1; // 用于使得状态转移方程成立
dp[1] = 1;
dp[i] = dp[i-1] + dp[i-2];
```

# 120. 三角形最小路径和
```cpp
//取容器中的最大最小值
//*max(min)_element(first,end,cmp);
return *min_element(vv.back().begin(), vv.back().end());//vv为二维vector
//返回二维vector中最后一行中的最小值
```

```cpp
triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1];//状态转移方程成立
```

# 221 最大正方形


# 121. 买卖股票的最佳时机
```cpp
dp[i] = max(dp[i-1],prices[i]-maxNum[i-1]); 
//动态规划 前i天的最大收益 = max{前i-1天的最大收益，第i天的价格-前i-1天中的最小价格}
maxNum[i] = min(maxNum[i-1],prices[i]);
//i天内的最小价格
```
# 198. 打家劫舍
```cpp
a[0] = nums[0];
a[1] = max(nums[0],nums[1]);
a[i] = max(a[i-1],a[i-2]+nums[i]);
```
# 213. 打家劫舍 II
```cpp
for(int i = 2; i < n-1; ++i)
    a[i] = max(a[i-1],a[i-2]+nums[i]);       
for(int i = 3; i < n ; ++i)
    b[i] = max(b[i-1],b[i-2]+nums[i]);
//对0~n-2和1~n-1号元素分别dp.取两者的最大值。因为只有这两种可能
```
# **337. 打家劫舍 III

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