#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    string s;
    cin>>s;
    int m = s.length();
    long long int sum = 0;
    //16 转 10
    for(int j = 0; j <m;++j)
    {
        
        char tmp = s.at(m-j-1);
        if( tmp >= '0' && tmp <= '9')
        {
            int a = tmp - '0';
            sum += a * pow(16,j);
        }
        else
        {
            int a = tmp - 'A' + 10;
            sum += a * pow(16,j);
        }
    }

    cout<<sum<<endl;

    return 0;
}