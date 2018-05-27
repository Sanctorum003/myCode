#include <iostream>
using namespace std;

int main(void)
{
    int cnt = 0;
    for(int i = 10000; i<=99999;++i)
    {
        int temp = i; // 12345
        int ge = i % 10;
        int shi = i % 100 / 10;
        int bai = i / 100 % 10;
        int qian = i / 1000 % 10;
        int wan = i / 10000;
        if(ge == 4 || shi == 4 || bai == 4 || qian == 4 || wan ==4 )
            cnt++;
    }

    cout<<99999-10000+1-cnt<<endl;
    return 0;
}