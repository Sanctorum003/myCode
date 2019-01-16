#include <iostream>
#include <sstream>    //使用stringstream需要引入这个头文件  
#include <cstdlib>
#include <cmath>
#include <cstdio>
using namespace std;

//模板函数：将string类型变量转换为常用的数值类型（此方法具有普遍适用性）  
template <class Type>  
Type stringToNum(const string& str)  
{  
    istringstream iss(str);  
    Type num;  
    iss >> num;  
    return num;      
}  

int main(void)
{
    string s;
    double res;
    cin>>s;
    if(s[0] == '-')
    cout<<"-";
    int pos = s.find('E');
    //cout<<pos<<endl;
    double m = stringToNum<double>(s.substr(1,pos-1));
    double p = stringToNum<int>(s.substr(pos+2,s.size()-1));
    if(s[pos+1] == '-')
        p = - p;
    
    double ji = pow(10,p);

    res = m * ji;
    // cout<<res<<endl;
    int jdu = s.find('.');
    int n = pos - jdu - 1 - p;
    cout<<n<<endl;
    if(n > 0)
        printf("%0.*f",n,res);
    else
        printf("%*f",-n,res);
    
    return 0;
}