#include <iostream>
using namespace std;

int main(void)
{
    char a;
    int b,c;
    cin>>a;
    cin>>b>>c;
    if(a == '+')
        cout<<b+c;
    else if(a == '-')
        cout<<b-c;
    else if(a == '*')
        cout<<b*c;
    else if(a =='/')
        cout<<b/c;
    return 0;
}