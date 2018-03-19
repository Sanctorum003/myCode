#include <iostream>
using namespace std;

int main(void)
{
// cout.setf(ios::fixed)——用定点格式显示浮点数；
// cout.setf(ios::showpoint)——显示浮点数小数点后的0；
// cout.precision(2)——设置精确度为2位并返回上一次的设置。
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    char f;
    double a,b,c,d;
    cin>>f;
    cin>>a>>b>>c>>d;
    
    if(f == '+')
        cout<<(a+c)<<"+"<<(b+d)<<"i"<<endl;
    else if(f == '-')
        cout<<(a-c)<<"+"<<(b-d)<<"i"<<endl;
    else if(f == '*')
        cout<<(a*c-b*d)<<"+"<<(b*c+a*d)<<"i"<<endl;
    else if(f == '/')
        cout<<(a*c+b*d)/(c*c+d*d)<<"+"<<(b*c-a*d)/(c*c+d*d)<<"i"<<endl;

    return 0;
}