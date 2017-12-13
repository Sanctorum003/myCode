#include <iostream>
using namespace std;

bool isRun(int year)
{
    if(year % 4 == 0 && year % 100 != 0)
        return true;

    if(year % 400 == 0)
        return true;

    return false;
}

int main(void)
{
    int year;
    cin>>year;
    bool res = isRun(year);
    if(res)
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}