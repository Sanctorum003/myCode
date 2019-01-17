#include <iostream>
using namespace std;
//(N-1)A+B,A+(N-1)B
int main(void)
{

    long long int n,a,b;
    cin>>n>>a>>b;
    if(n==1)
    {
        if(a==b) cout<<1<<endl;
        else cout<<0<<endl;
    }
    else if(n > 1)
    {
        if(a > b) cout<<0<<endl;
        else    cout<<(a+(n-1)*b)-((n-1)*a+b)+1<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    
    return 0;
}