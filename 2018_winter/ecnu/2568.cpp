#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        string s =to_string(a+b);
        cout<<s.size()<<endl;
    }
    
    return 0;
}