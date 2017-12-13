//LeetCode
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int *dp = new int[n+1];
        dp[0] = nums[0];
        int m = dp[0];
        
        for(int i = 1; i < n ;++i)
        {
            dp[i] = nums[i] + ( dp[i-1] > 0 ? dp[i-1]:0); 
            m = max(dp[i],m);
        }

        return m;
    }
};

int main(void)
{

    return 0;
}