//https://blog.csdn.net/qq_34594236/article/details/60145451
#include <iostream>
using namespace std;

int main(void)
{
    for(int i = 1 ; i<= 49 ;++i)
        for(int j = i +2 ; j <=49;++j)
            if(1225 - i - i - 1 - j - j - 1 + i * (i+1)+j*(j+1) == 2015)
                cout<<i<<endl;
    return 0;
}