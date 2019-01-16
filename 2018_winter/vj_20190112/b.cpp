#include <iostream>
using namespace std;

//计算n的阶乘 
long long int jc(long long int n){
    long long int i,res=1;
    for(i=1;i<=n;i++){
        res=res*i;
    } 
    return res;
}

//计算组合数
long long int C(long long int m,long long int n){
    return (jc(n))/(jc(m)*jc(n-m));
} 

long long int main(void)
{

    long long int n,a,b;
    cin>>n>>a>>b;
    if(n == 1 && a == b) cout<<1<<endl;
    else if(n <= 1 || b < a || a<=0 || b <=0 ) cout<<0<<endl;
    else if( a == b) cout<<1<<endl;
    else if( n == 2) cout<<1<<endl;
    else cout<<2+C(n-2,b-a+1)<<endl;
    return 0;
}