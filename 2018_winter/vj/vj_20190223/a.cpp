#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>  
#define ll long long
using namespace std;


typedef struct fenshu
{
    ll fm;
    ll fz;
} fs;


ll gcd(ll x,ll y){//递归形式辗转相除法
	return (!y)?x:gcd(y,x%y);
}


int main(void)
{
    int n;
    cin>>n;
    fs res[n]={0};
    fs a[3];
    for(int i = 0 ; i < n ; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            scanf("%lld/%lld",&a[j].fz,&a[j].fm);
            // cout<<a[j].fz<<"/"<<a[j].fm<<endl;
        }

        ll gbs = a[0].fm*a[1].fm*a[2].fm;
        // cout<<gbs<<endl;

        res[i].fm = 0;
        res[i].fz = 0;
        res[i].fm = gbs;
        
        // cout<<a[2].fz * (gbs / a[2].fm)<<endl;
        for(int j = 0 ; j < 3; ++j)
        {          
            res[i].fz += a[j].fz * (gbs / a[j].fm);
        }

        ll xs = gcd(res[i].fz,res[i].fm);//相关系数
        res[i].fz /=xs;
        res[i].fm /=xs;
    }

    for(int i = 0; i < n; ++i)
    {
        cout<<res[i].fz<<"/"<<res[i].fm<<endl;
    }

    return 0;
}