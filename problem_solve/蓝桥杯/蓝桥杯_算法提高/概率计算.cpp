#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;  
  
double dp[105][5055];//dp[i][j]表示取i个数时和为j的概率   
  
int n, a, b, x;  
  
int main() {  
    scanf("%d %d %d %d", &n, &a, &b, &x);  
    memset(dp, 0, sizeof(dp));  
    dp[0][0] = 1;  
    /*for(int i = 1; i < 5055; i ++) { 
        dp[0][i] = 0; 
    }*/  
    int sum = b - a + 1;  
    for(int i = 1; i <= n; i ++) { //取i个数  从1~n
        for(int j = 0; j <= x; j ++) {//和为j 从0~x
            for(int k = a; k <= b; k ++) {//取第i个数的时候取的是值是k
                if(j >= k) //总和j必须大于等于单次取的数的大小，不然概率无意义
                    //在第i次取数和j时，遍历所有取数的方式（即K从a~b取）
                    //如果可取，则整个概率计算(需多个概率相加)中的一步。
                    //并且这一步的概率分两个阶段：1)dp[i-1][j-k]取第i-1次和为j-k的概率2)第i次取k是是一种情况：概率为1/sum。两阶段相乘。
                    dp[i][j] += dp[i-1][j-k] / sum;  
            }  
        }  
    }   

    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <=x;++j)
            printf("%.4lf\t", dp[i][j]);
        cout<<endl;
    }


    printf("%.4lf\n", dp[n][x]);  
    return 0;  
}  