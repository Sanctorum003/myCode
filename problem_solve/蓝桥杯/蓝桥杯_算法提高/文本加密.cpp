#include <iostream>
#include <algorithm>
using namespace std;

int func(int c)
{//65 97
    if(c>=65 && c<90)
        return c+1;
    if(c == 90)
        return 97;
    if(c>=97 && c<122)
        return c+1;
    if(c == 122)
        return 65;
    return c;
}

int main(void)
{
    string s;
    cin>>s;
    transform(s.begin(),s.end(),s.begin(),func);
    cout<<s<<endl;
    return 0;
}