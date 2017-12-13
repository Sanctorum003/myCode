#include <iostream>
using namespace std;

int main(void)
{
    // cout.setf(ios::fixed);
    // cout.setf(ios::showpoint);
    // cout.precision(2);
    char f;
    double a,b,c,d;
    cin>>a>>b;
    cin>>f;
    cin>>c>>d;

    if(c== 0 && d == 0)
    {
        cout<<"error"<<endl;
        return 0;
    }
    
    if(f == '+')
        if(b+d > 0)
            cout<<(a+c)<<"+"<<(b+d)<<"i"<<endl;
        else if(b+d == 0)
            cout<<(a+c)<<endl;
        else 
             cout<<(a+c)<<(b+d)<<"i"<<endl;
    else if(f == '-')
        if(b-d > 0)
            cout<<(a-c)<<"+"<<(b-d)<<"i"<<endl;
        else if(b-d == 0)
            cout<<(a-c)<<endl;        
        else
            cout<<(a-c)<<(b-d)<<"i"<<endl;        
    else if(f == '*')
        if((b*c+a*d) >0 )
            cout<<(a*c-b*d)<<"+"<<(b*c+a*d)<<"i"<<endl;
        else if((b*c+a*d) == 0)
            cout<<(a*c-b*d)<<endl;
        else
            cout<<(a*c-b*d)<<(b*c+a*d)<<"i"<<endl;       
    else if(f == '/')
        if((b*c-a*d)/(c*c+d*d) > 0)
            cout<<(a*c+b*d)/(c*c+d*d)<<"+"<<(b*c-a*d)/(c*c+d*d)<<"i"<<endl;
        else if((b*c-a*d)/(c*c+d*d) == 0)
            cout<<(a*c+b*d)/(c*c+d*d)<<endl;
        else
            cout<<(a*c+b*d)/(c*c+d*d)<<(b*c-a*d)/(c*c+d*d)<<"i"<<endl;
    return 0;
}