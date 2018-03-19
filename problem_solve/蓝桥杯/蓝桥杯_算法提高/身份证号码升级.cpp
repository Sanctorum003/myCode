#include <iostream>
#include <cstdio>
#define digit(a) (a-48)
using namespace std;

int xishu[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char xishu2[11] = {'1', '0', 'x', '9', '8', '7', '6', '5', '4', '3', '2'};

int main(void)
{
    string s;
    cin>>s;
    char s18;
    s.insert(s.begin()+6,'9');
    s.insert(s.begin()+6,'1');

    int sum = 0;
    for(int i = 0; i < 17;++i)
    {
        sum += xishu[i] * digit(s[i]);
    }
    
    s18 = xishu2[sum % 11];
    s.push_back(s18);
    cout<<s;
    return 0;
}