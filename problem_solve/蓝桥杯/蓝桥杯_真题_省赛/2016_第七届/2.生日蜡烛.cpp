#include <iostream>
using namespace std;

int main(void)
{
    for(int i = 1; ;++i)
    {
        int sum  = i;
        for(int j = i+1;;++j)
        {
            sum += j;
            if(sum  == 236)
            {
                cout<<i<<endl;
                return 0;
            }
            else if(sum > 236)
                break;
        }
    }

    return 0;
}