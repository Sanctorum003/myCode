#include <iostream>
using namespace std;

int main(void)
{
    for(int i = 1; i <=9 ;++i)
        for(int j = 0; j <=9 ; ++j)
            for(int k = 0; k <= 9;++k)
                for(int l = 0; l <= 9; ++l)
                    if(l == i && k ==j)
                        cout<<i<<j<<k<<l<<endl;
    
    return 0;
}