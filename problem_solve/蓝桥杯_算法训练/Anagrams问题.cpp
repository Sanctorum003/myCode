#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    string a,b;
    cin>>a>>b;
    //transform(first,last,result,op);
    //first是容器的首迭代器，last为容器的末迭代器，
    //result为存放结果的容器，op为要进行操作的一元函数对象或sturct、class。
    transform(a.begin(),a.end(),a.begin(),::tolower);
    transform(b.begin(),b.end(),b.begin(),::tolower);

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    if(a == b)
        cout<<"Y"<<endl;
    else
        cout<<"N"<<endl;
    
    return 0;
}