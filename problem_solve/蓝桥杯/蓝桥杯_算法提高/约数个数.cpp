#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin>>n;
    int cnt = 0;
    for(int i = 1; i<=n; ++i)
    {
        if(n % i == 0)
            cnt++;
    }

    cout<<cnt<<endl;
    return 0;
}