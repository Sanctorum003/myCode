#include <iostream>
using namespace std;

int cnt = 0;

bool func(int k,int m, int n)
{
    if(m > 0)
    {
        func(k+1,m-1,n);
    }

    if(n > 0)
    {
        if(k > 0)
            func(k-1,m,n-1);


    }
    
    if( m== 0 && n==0)
        cnt++;

    return true;
}

int main(void)
{
    int k = 0;// 鞋子的剩余量
    int m;//还鞋
    int n;//租鞋
    cin>>m>>n;
    func(k,m,n);
    cout<<cnt<<endl;
    return 0;
}