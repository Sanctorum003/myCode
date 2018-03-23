#include <iostream>
using namespace std;

int lcm(int i,int j)
{// 24 16  24mod16=8 16 8  16mod8=0  
    int a = i;
    int b = j;
    do
    {
        int  n = a%b;
        a=b;
        b=n;
    }while(b != 0);
    return i*j/a;
}


int main(void)
{
    int a,b,c;
    cin>>a>>b>>c;
    int ab = lcm(a,b);
    int abc = lcm(ab,c);
    cout<<abc<<endl;
    return 0;
}