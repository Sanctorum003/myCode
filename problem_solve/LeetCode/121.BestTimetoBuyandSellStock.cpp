#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int curMax = 0;
        int sofarMax = 0;
        for(int i = 1; i < n; ++i)
        {
            curMax = max(0,curMax+=(prices[i]-prices[i-1]));
            sofarMax = max(curMax,sofarMax);
        }

        return sofarMax;
    }
};

int main(void)
{

    return 0;
}